# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ljs/myRosspace/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ljs/myRosspace/build

# Include any dependencies generated for this target.
include test_pkg/CMakeFiles/testpub_node.dir/depend.make

# Include the progress variables for this target.
include test_pkg/CMakeFiles/testpub_node.dir/progress.make

# Include the compile flags for this target's objects.
include test_pkg/CMakeFiles/testpub_node.dir/flags.make

test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o: test_pkg/CMakeFiles/testpub_node.dir/flags.make
test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o: /home/ljs/myRosspace/src/test_pkg/src/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljs/myRosspace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o"
	cd /home/ljs/myRosspace/build/test_pkg && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testpub_node.dir/src/test.cpp.o -c /home/ljs/myRosspace/src/test_pkg/src/test.cpp

test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testpub_node.dir/src/test.cpp.i"
	cd /home/ljs/myRosspace/build/test_pkg && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljs/myRosspace/src/test_pkg/src/test.cpp > CMakeFiles/testpub_node.dir/src/test.cpp.i

test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testpub_node.dir/src/test.cpp.s"
	cd /home/ljs/myRosspace/build/test_pkg && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljs/myRosspace/src/test_pkg/src/test.cpp -o CMakeFiles/testpub_node.dir/src/test.cpp.s

test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o.requires:

.PHONY : test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o.requires

test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o.provides: test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o.requires
	$(MAKE) -f test_pkg/CMakeFiles/testpub_node.dir/build.make test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o.provides.build
.PHONY : test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o.provides

test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o.provides.build: test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o


# Object files for target testpub_node
testpub_node_OBJECTS = \
"CMakeFiles/testpub_node.dir/src/test.cpp.o"

# External object files for target testpub_node
testpub_node_EXTERNAL_OBJECTS =

/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: test_pkg/CMakeFiles/testpub_node.dir/build.make
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /opt/ros/melodic/lib/libroscpp.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /opt/ros/melodic/lib/librosconsole.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /opt/ros/melodic/lib/librostime.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /opt/ros/melodic/lib/libcpp_common.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/ljs/myRosspace/devel/lib/test_pkg/testpub_node: test_pkg/CMakeFiles/testpub_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ljs/myRosspace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/ljs/myRosspace/devel/lib/test_pkg/testpub_node"
	cd /home/ljs/myRosspace/build/test_pkg && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testpub_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test_pkg/CMakeFiles/testpub_node.dir/build: /home/ljs/myRosspace/devel/lib/test_pkg/testpub_node

.PHONY : test_pkg/CMakeFiles/testpub_node.dir/build

test_pkg/CMakeFiles/testpub_node.dir/requires: test_pkg/CMakeFiles/testpub_node.dir/src/test.cpp.o.requires

.PHONY : test_pkg/CMakeFiles/testpub_node.dir/requires

test_pkg/CMakeFiles/testpub_node.dir/clean:
	cd /home/ljs/myRosspace/build/test_pkg && $(CMAKE_COMMAND) -P CMakeFiles/testpub_node.dir/cmake_clean.cmake
.PHONY : test_pkg/CMakeFiles/testpub_node.dir/clean

test_pkg/CMakeFiles/testpub_node.dir/depend:
	cd /home/ljs/myRosspace/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljs/myRosspace/src /home/ljs/myRosspace/src/test_pkg /home/ljs/myRosspace/build /home/ljs/myRosspace/build/test_pkg /home/ljs/myRosspace/build/test_pkg/CMakeFiles/testpub_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test_pkg/CMakeFiles/testpub_node.dir/depend

