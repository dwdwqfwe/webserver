#include <mysql/mysql.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <pthread.h>
#include "sql_pool.h"

using namespace std;

connection_pool::connection_pool()
{
	m_CurConn=0;
	m_FreeConn=0;
	m_MaxConn=0;
}

connection_pool *connection_pool::GetInstance()
{
	static connection_pool connpoll;
	return &connpoll;
}

//构造初始化
void connection_pool::init(string url, string User, string PassWord, string DBName, int Port, int MaxConn, int close_log)
{
	m_url=url;
	m_User=User;
	m_PassWord=PassWord;
	m_DatabaseName=DBName;
	m_Port=Port;
	for(int i=0;i<MaxConn;i++){
		MYSQL *con=NULL;
		con=mysql_init(con);
		if(con==NULL){
			LOG_ERROR("mysql error");
			exit(1);
		}
		con=mysql_real_connect(con,url.c_str(),User.c_str(),PassWord.c_str(),m_DatabaseName.c_str(),
		Port,NULL,0);
		if(con==NULL){
			LOG_ERROR("mysql error");
			exit(1);
		}
		m_FreeConn++;
		connList.push_back(con);
	}
	reserve=sem(MaxConn);
	m_MaxConn=m_FreeConn;

}


//当有请求时，从数据库连接池中返回一个可用连接，更新使用和空闲连接数
MYSQL *connection_pool::GetConnection()
{
	reserve.wait();
	lock.lock();
	if(m_FreeConn==0){
		lock.unlock();
		return NULL;
	}
	MYSQL *con;
	con=connList.front();
	connList.pop_front();
	m_FreeConn--;
	m_CurConn++;
	lock.unlock();
	return con;
}

//释放当前使用的连接
bool connection_pool::ReleaseConnection(MYSQL *con)
{
	if(!con)
		return false;
	lock.lock();
	connList.push_back(con);
	++m_FreeConn;
	--m_CurConn;
	lock.unlock();
	reserve.post();
	return true;
}

//销毁数据库连接池
void connection_pool::DestroyPool()
{
	lock.lock();
	if(connList.size()>0){
		std::list<MYSQL*>::iterator it;
		for(it=connList.begin();it!=connList.end();it++){
			MYSQL *con=*it;
			mysql_close(con);
		}
		m_FreeConn=0;
		m_CurConn=0;
		connList.clear();
	}
	lock.unlock();
}

//当前空闲的连接数
int connection_pool::GetFreeConn()
{
	lock.lock();
	int temp=m_FreeConn;
	lock.unlock();
	return temp;
}

connection_pool::~connection_pool()
{
	DestroyPool();
}

connectionRAII::connectionRAII(MYSQL **SQL, connection_pool *connPool){
	*SQL=connPool->GetConnection();
	conRAII=*SQL;
	poolRAII=connPool;
}

connectionRAII::~connectionRAII(){
	poolRAII->ReleaseConnection(conRAII);
}