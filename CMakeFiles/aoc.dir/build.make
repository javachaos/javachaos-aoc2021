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
include CMakeFiles/aoc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/aoc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/aoc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aoc.dir/flags.make

CMakeFiles/aoc.dir/AOC.cpp.o: CMakeFiles/aoc.dir/flags.make
CMakeFiles/aoc.dir/AOC.cpp.o: AOC.cpp
CMakeFiles/aoc.dir/AOC.cpp.o: CMakeFiles/aoc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fred/Documents/javachaos-aoc2021/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aoc.dir/AOC.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aoc.dir/AOC.cpp.o -MF CMakeFiles/aoc.dir/AOC.cpp.o.d -o CMakeFiles/aoc.dir/AOC.cpp.o -c /home/fred/Documents/javachaos-aoc2021/AOC.cpp

CMakeFiles/aoc.dir/AOC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aoc.dir/AOC.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fred/Documents/javachaos-aoc2021/AOC.cpp > CMakeFiles/aoc.dir/AOC.cpp.i

CMakeFiles/aoc.dir/AOC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aoc.dir/AOC.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fred/Documents/javachaos-aoc2021/AOC.cpp -o CMakeFiles/aoc.dir/AOC.cpp.s

# Object files for target aoc
aoc_OBJECTS = \
"CMakeFiles/aoc.dir/AOC.cpp.o"

# External object files for target aoc
aoc_EXTERNAL_OBJECTS =

bin/aoc: CMakeFiles/aoc.dir/AOC.cpp.o
bin/aoc: CMakeFiles/aoc.dir/build.make
bin/aoc: CMakeFiles/aoc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fred/Documents/javachaos-aoc2021/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/aoc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aoc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aoc.dir/build: bin/aoc
.PHONY : CMakeFiles/aoc.dir/build

CMakeFiles/aoc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aoc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aoc.dir/clean

CMakeFiles/aoc.dir/depend:
	cd /home/fred/Documents/javachaos-aoc2021 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fred/Documents/javachaos-aoc2021 /home/fred/Documents/javachaos-aoc2021 /home/fred/Documents/javachaos-aoc2021 /home/fred/Documents/javachaos-aoc2021 /home/fred/Documents/javachaos-aoc2021/CMakeFiles/aoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aoc.dir/depend

