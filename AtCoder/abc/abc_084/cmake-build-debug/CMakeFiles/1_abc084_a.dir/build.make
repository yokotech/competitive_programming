# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1_abc084_a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1_abc084_a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1_abc084_a.dir/flags.make

CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.o: CMakeFiles/1_abc084_a.dir/flags.make
CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.o: ../1_abc084_a.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.o -c /Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084/1_abc084_a.cpp

CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084/1_abc084_a.cpp > CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.i

CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084/1_abc084_a.cpp -o CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.s

# Object files for target 1_abc084_a
1_abc084_a_OBJECTS = \
"CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.o"

# External object files for target 1_abc084_a
1_abc084_a_EXTERNAL_OBJECTS =

1_abc084_a: CMakeFiles/1_abc084_a.dir/1_abc084_a.cpp.o
1_abc084_a: CMakeFiles/1_abc084_a.dir/build.make
1_abc084_a: CMakeFiles/1_abc084_a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1_abc084_a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1_abc084_a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1_abc084_a.dir/build: 1_abc084_a

.PHONY : CMakeFiles/1_abc084_a.dir/build

CMakeFiles/1_abc084_a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1_abc084_a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1_abc084_a.dir/clean

CMakeFiles/1_abc084_a.dir/depend:
	cd /Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084 /Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084 /Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084/cmake-build-debug /Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084/cmake-build-debug /Users/yokoyama/development/competitive_programming/AtCoder/abc/abc_084/cmake-build-debug/CMakeFiles/1_abc084_a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1_abc084_a.dir/depend

