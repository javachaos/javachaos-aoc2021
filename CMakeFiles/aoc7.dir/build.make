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
CMAKE_SOURCE_DIR = /home/fred/Documents/javachaos-aoc2021

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fred/Documents/javachaos-aoc2021

# Include any dependencies generated for this target.
include CMakeFiles/aoc7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/aoc7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/aoc7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aoc7.dir/flags.make

CMakeFiles/aoc7.dir/AOC7.cpp.o: CMakeFiles/aoc7.dir/flags.make
CMakeFiles/aoc7.dir/AOC7.cpp.o: AOC7.cpp
CMakeFiles/aoc7.dir/AOC7.cpp.o: CMakeFiles/aoc7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fred/Documents/javachaos-aoc2021/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aoc7.dir/AOC7.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aoc7.dir/AOC7.cpp.o -MF CMakeFiles/aoc7.dir/AOC7.cpp.o.d -o CMakeFiles/aoc7.dir/AOC7.cpp.o -c /home/fred/Documents/javachaos-aoc2021/AOC7.cpp

CMakeFiles/aoc7.dir/AOC7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aoc7.dir/AOC7.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fred/Documents/javachaos-aoc2021/AOC7.cpp > CMakeFiles/aoc7.dir/AOC7.cpp.i

CMakeFiles/aoc7.dir/AOC7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aoc7.dir/AOC7.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fred/Documents/javachaos-aoc2021/AOC7.cpp -o CMakeFiles/aoc7.dir/AOC7.cpp.s

# Object files for target aoc7
aoc7_OBJECTS = \
"CMakeFiles/aoc7.dir/AOC7.cpp.o"

# External object files for target aoc7
aoc7_EXTERNAL_OBJECTS =

bin/aoc7: CMakeFiles/aoc7.dir/AOC7.cpp.o
bin/aoc7: CMakeFiles/aoc7.dir/build.make
bin/aoc7: CMakeFiles/aoc7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fred/Documents/javachaos-aoc2021/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/aoc7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aoc7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aoc7.dir/build: bin/aoc7
.PHONY : CMakeFiles/aoc7.dir/build

CMakeFiles/aoc7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aoc7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aoc7.dir/clean

CMakeFiles/aoc7.dir/depend:
	cd /home/fred/Documents/javachaos-aoc2021 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fred/Documents/javachaos-aoc2021 /home/fred/Documents/javachaos-aoc2021 /home/fred/Documents/javachaos-aoc2021 /home/fred/Documents/javachaos-aoc2021 /home/fred/Documents/javachaos-aoc2021/CMakeFiles/aoc7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aoc7.dir/depend

