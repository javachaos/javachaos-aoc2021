cmake_minimum_required(VERSION 3.10)
project(heap VERSION 1.0)

SET(CMAKE_BUILD_TYPE distribution)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED True)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -O3 -lgmpxx -lgmp -fopenmp")
MESSAGE("Arch: " ${ARCH})
MESSAGE("Using compiler: " ${CMAKE_CXX_COMPILER})
MESSAGE("Using GCC Options: " ${CMAKE_CXX_FLAGS_DISTRIBUTION})
ADD_DEFINITIONS(${GCC_COVERAGE_COMPILE_FLAGS})
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Try to find the GNU Multiple Precision Arithmetic Library (GMP)
find_path(GMP_INCLUDE_DIR gmp.h
    PATHS /usr/include /usr/local/include )

find_library(GMP_LIBRARY NAMES gmp
    PATHS /usr/lib /usr/local/lib)

if(GMP_INCLUDE_DIR AND GMP_LIBRARY)
    get_filename_component(GMP_LIBRARY_DIR ${GMP_LIBRARY} PATH)
    set(GMP_FOUND TRUE)
endif()

if(GMP_FOUND)
   if(NOT GMP_FIND_QUIETLY)
      MESSAGE(STATUS "Found GMP: ${GMP_LIBRARY}")
   endif()
elseif(GMP_FOUND)
   if(GMP_FIND_REQUIRED)
      message(FATAL_ERROR "Could not find GMP")
   endif()
endif()

add_executable (aoc AOC.cpp) 
add_executable (aoc1 AOC1.cpp) 
add_executable (aoc2 AOC2.cpp) 
add_executable (aoc3 AOC3.cpp) 
#add_executable (aoc4 AOC4.cpp) 
#add_executable (aoc5 AOC5.cpp) 
add_executable (aoc6 AOC6.cpp) 
add_executable (aoc7 AOC7.cpp)
target_link_libraries(aoc6 gmpxx gmp ${GMP_LIBRARY})
target_include_directories(aoc6 PUBLIC "${PROJECT_BINARY_DIR} ${GMP_INCLUDE_DIR}")