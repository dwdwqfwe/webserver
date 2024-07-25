cmake_minimum_required(VERSION 3.0.0)
set(CXX_STANDARD 17)
project(webserver)
set(BEGIN ${PROJECT_SOURCE_DIR})
set(INC ${CMAKE_CURRENT_SOURCE_DIR}/http  
${CMAKE_CURRENT_SOURCE_DIR}/lock 
${CMAKE_CURRENT_SOURCE_DIR}/log 
${CMAKE_CURRENT_SOURCE_DIR}/mysql_pool 
${CMAKE_CURRENT_SOURCE_DIR}/thread_pool 
${CMAKE_CURRENT_SOURCE_DIR}/timer ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/http/*.cpp  
${CMAKE_CURRENT_SOURCE_DIR}/lock/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/log/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/mysql_pool/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/thread_pool/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/timer/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)
include_directories(INC)
link_directories(/usr/lib/x86_64-linux-gnu)
add_executable(a.out ${SRC})
target_link_libraries(a.out mysqlclient)