# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/fred/AOC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fred/AOC/build

# Include any dependencies generated for this target.
include CMakeFiles/aoc5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aoc5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aoc5.dir/flags.make

CMakeFiles/aoc5.dir/AOC5.cpp.o: CMakeFiles/aoc5.dir/flags.make
CMakeFiles/aoc5.dir/AOC5.cpp.o: ../AOC5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fred/AOC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aoc5.dir/AOC5.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aoc5.dir/AOC5.cpp.o -c /home/fred/AOC/AOC5.cpp

CMakeFiles/aoc5.dir/AOC5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aoc5.dir/AOC5.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fred/AOC/AOC5.cpp > CMakeFiles/aoc5.dir/AOC5.cpp.i

CMakeFiles/aoc5.dir/AOC5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aoc5.dir/AOC5.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fred/AOC/AOC5.cpp -o CMakeFiles/aoc5.dir/AOC5.cpp.s

# Object files for target aoc5
aoc5_OBJECTS = \
"CMakeFiles/aoc5.dir/AOC5.cpp.o"

# External object files for target aoc5
aoc5_EXTERNAL_OBJECTS =

bin/aoc5: CMakeFiles/aoc5.dir/AOC5.cpp.o
bin/aoc5: CMakeFiles/aoc5.dir/build.make
bin/aoc5: CMakeFiles/aoc5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fred/AOC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/aoc5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aoc5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aoc5.dir/build: bin/aoc5

.PHONY : CMakeFiles/aoc5.dir/build

CMakeFiles/aoc5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aoc5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aoc5.dir/clean

CMakeFiles/aoc5.dir/depend:
	cd /home/fred/AOC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fred/AOC /home/fred/AOC /home/fred/AOC/build /home/fred/AOC/build /home/fred/AOC/build/CMakeFiles/aoc5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aoc5.dir/depend

