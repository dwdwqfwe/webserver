# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jh/work/webserver/my_webserver/webserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jh/work/webserver/my_webserver/webserver/build

# Include any dependencies generated for this target.
include CMakeFiles/a.out.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/a.out.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/a.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.out.dir/flags.make

CMakeFiles/a.out.dir/config.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/config.cpp.o: ../config.cpp
CMakeFiles/a.out.dir/config.cpp.o: CMakeFiles/a.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jh/work/webserver/my_webserver/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a.out.dir/config.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.dir/config.cpp.o -MF CMakeFiles/a.out.dir/config.cpp.o.d -o CMakeFiles/a.out.dir/config.cpp.o -c /home/jh/work/webserver/my_webserver/webserver/config.cpp

CMakeFiles/a.out.dir/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jh/work/webserver/my_webserver/webserver/config.cpp > CMakeFiles/a.out.dir/config.cpp.i

CMakeFiles/a.out.dir/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jh/work/webserver/my_webserver/webserver/config.cpp -o CMakeFiles/a.out.dir/config.cpp.s

CMakeFiles/a.out.dir/http/http_conn.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/http/http_conn.cpp.o: ../http/http_conn.cpp
CMakeFiles/a.out.dir/http/http_conn.cpp.o: CMakeFiles/a.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jh/work/webserver/my_webserver/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/a.out.dir/http/http_conn.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.dir/http/http_conn.cpp.o -MF CMakeFiles/a.out.dir/http/http_conn.cpp.o.d -o CMakeFiles/a.out.dir/http/http_conn.cpp.o -c /home/jh/work/webserver/my_webserver/webserver/http/http_conn.cpp

CMakeFiles/a.out.dir/http/http_conn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/http/http_conn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jh/work/webserver/my_webserver/webserver/http/http_conn.cpp > CMakeFiles/a.out.dir/http/http_conn.cpp.i

CMakeFiles/a.out.dir/http/http_conn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/http/http_conn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jh/work/webserver/my_webserver/webserver/http/http_conn.cpp -o CMakeFiles/a.out.dir/http/http_conn.cpp.s

CMakeFiles/a.out.dir/log/log.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/log/log.cpp.o: ../log/log.cpp
CMakeFiles/a.out.dir/log/log.cpp.o: CMakeFiles/a.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jh/work/webserver/my_webserver/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/a.out.dir/log/log.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.dir/log/log.cpp.o -MF CMakeFiles/a.out.dir/log/log.cpp.o.d -o CMakeFiles/a.out.dir/log/log.cpp.o -c /home/jh/work/webserver/my_webserver/webserver/log/log.cpp

CMakeFiles/a.out.dir/log/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/log/log.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jh/work/webserver/my_webserver/webserver/log/log.cpp > CMakeFiles/a.out.dir/log/log.cpp.i

CMakeFiles/a.out.dir/log/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/log/log.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jh/work/webserver/my_webserver/webserver/log/log.cpp -o CMakeFiles/a.out.dir/log/log.cpp.s

CMakeFiles/a.out.dir/main.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/main.cpp.o: ../main.cpp
CMakeFiles/a.out.dir/main.cpp.o: CMakeFiles/a.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jh/work/webserver/my_webserver/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/a.out.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.dir/main.cpp.o -MF CMakeFiles/a.out.dir/main.cpp.o.d -o CMakeFiles/a.out.dir/main.cpp.o -c /home/jh/work/webserver/my_webserver/webserver/main.cpp

CMakeFiles/a.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jh/work/webserver/my_webserver/webserver/main.cpp > CMakeFiles/a.out.dir/main.cpp.i

CMakeFiles/a.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jh/work/webserver/my_webserver/webserver/main.cpp -o CMakeFiles/a.out.dir/main.cpp.s

CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.o: ../mysql_pool/sql_pool.cpp
CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.o: CMakeFiles/a.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jh/work/webserver/my_webserver/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.o -MF CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.o.d -o CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.o -c /home/jh/work/webserver/my_webserver/webserver/mysql_pool/sql_pool.cpp

CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jh/work/webserver/my_webserver/webserver/mysql_pool/sql_pool.cpp > CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.i

CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jh/work/webserver/my_webserver/webserver/mysql_pool/sql_pool.cpp -o CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.s

CMakeFiles/a.out.dir/timer/lst_timer.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/timer/lst_timer.cpp.o: ../timer/lst_timer.cpp
CMakeFiles/a.out.dir/timer/lst_timer.cpp.o: CMakeFiles/a.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jh/work/webserver/my_webserver/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/a.out.dir/timer/lst_timer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.dir/timer/lst_timer.cpp.o -MF CMakeFiles/a.out.dir/timer/lst_timer.cpp.o.d -o CMakeFiles/a.out.dir/timer/lst_timer.cpp.o -c /home/jh/work/webserver/my_webserver/webserver/timer/lst_timer.cpp

CMakeFiles/a.out.dir/timer/lst_timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/timer/lst_timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jh/work/webserver/my_webserver/webserver/timer/lst_timer.cpp > CMakeFiles/a.out.dir/timer/lst_timer.cpp.i

CMakeFiles/a.out.dir/timer/lst_timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/timer/lst_timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jh/work/webserver/my_webserver/webserver/timer/lst_timer.cpp -o CMakeFiles/a.out.dir/timer/lst_timer.cpp.s

CMakeFiles/a.out.dir/webserver.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/webserver.cpp.o: ../webserver.cpp
CMakeFiles/a.out.dir/webserver.cpp.o: CMakeFiles/a.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jh/work/webserver/my_webserver/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/a.out.dir/webserver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.dir/webserver.cpp.o -MF CMakeFiles/a.out.dir/webserver.cpp.o.d -o CMakeFiles/a.out.dir/webserver.cpp.o -c /home/jh/work/webserver/my_webserver/webserver/webserver.cpp

CMakeFiles/a.out.dir/webserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/webserver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jh/work/webserver/my_webserver/webserver/webserver.cpp > CMakeFiles/a.out.dir/webserver.cpp.i

CMakeFiles/a.out.dir/webserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/webserver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jh/work/webserver/my_webserver/webserver/webserver.cpp -o CMakeFiles/a.out.dir/webserver.cpp.s

# Object files for target a.out
a_out_OBJECTS = \
"CMakeFiles/a.out.dir/config.cpp.o" \
"CMakeFiles/a.out.dir/http/http_conn.cpp.o" \
"CMakeFiles/a.out.dir/log/log.cpp.o" \
"CMakeFiles/a.out.dir/main.cpp.o" \
"CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.o" \
"CMakeFiles/a.out.dir/timer/lst_timer.cpp.o" \
"CMakeFiles/a.out.dir/webserver.cpp.o"

# External object files for target a.out
a_out_EXTERNAL_OBJECTS =

a.out: CMakeFiles/a.out.dir/config.cpp.o
a.out: CMakeFiles/a.out.dir/http/http_conn.cpp.o
a.out: CMakeFiles/a.out.dir/log/log.cpp.o
a.out: CMakeFiles/a.out.dir/main.cpp.o
a.out: CMakeFiles/a.out.dir/mysql_pool/sql_pool.cpp.o
a.out: CMakeFiles/a.out.dir/timer/lst_timer.cpp.o
a.out: CMakeFiles/a.out.dir/webserver.cpp.o
a.out: CMakeFiles/a.out.dir/build.make
a.out: CMakeFiles/a.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jh/work/webserver/my_webserver/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable a.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.out.dir/build: a.out
.PHONY : CMakeFiles/a.out.dir/build

CMakeFiles/a.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.out.dir/clean

CMakeFiles/a.out.dir/depend:
	cd /home/jh/work/webserver/my_webserver/webserver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jh/work/webserver/my_webserver/webserver /home/jh/work/webserver/my_webserver/webserver /home/jh/work/webserver/my_webserver/webserver/build /home/jh/work/webserver/my_webserver/webserver/build /home/jh/work/webserver/my_webserver/webserver/build/CMakeFiles/a.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.out.dir/depend

