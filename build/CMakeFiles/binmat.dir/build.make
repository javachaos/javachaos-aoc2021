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
include CMakeFiles/binmat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/binmat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binmat.dir/flags.make

CMakeFiles/binmat.dir/BinaryMatrix.c.o: CMakeFiles/binmat.dir/flags.make
CMakeFiles/binmat.dir/BinaryMatrix.c.o: ../BinaryMatrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fred/AOC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/binmat.dir/BinaryMatrix.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/binmat.dir/BinaryMatrix.c.o   -c /home/fred/AOC/BinaryMatrix.c

CMakeFiles/binmat.dir/BinaryMatrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/binmat.dir/BinaryMatrix.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fred/AOC/BinaryMatrix.c > CMakeFiles/binmat.dir/BinaryMatrix.c.i

CMakeFiles/binmat.dir/BinaryMatrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/binmat.dir/BinaryMatrix.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fred/AOC/BinaryMatrix.c -o CMakeFiles/binmat.dir/BinaryMatrix.c.s

# Object files for target binmat
binmat_OBJECTS = \
"CMakeFiles/binmat.dir/BinaryMatrix.c.o"

# External object files for target binmat
binmat_EXTERNAL_OBJECTS =

libbinmat.a: CMakeFiles/binmat.dir/BinaryMatrix.c.o
libbinmat.a: CMakeFiles/binmat.dir/build.make
libbinmat.a: CMakeFiles/binmat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fred/AOC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libbinmat.a"
	$(CMAKE_COMMAND) -P CMakeFiles/binmat.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binmat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binmat.dir/build: libbinmat.a

.PHONY : CMakeFiles/binmat.dir/build

CMakeFiles/binmat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/binmat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/binmat.dir/clean

CMakeFiles/binmat.dir/depend:
	cd /home/fred/AOC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fred/AOC /home/fred/AOC /home/fred/AOC/build /home/fred/AOC/build /home/fred/AOC/build/CMakeFiles/binmat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binmat.dir/depend

