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
CMAKE_SOURCE_DIR = /__w/OverflowProject/OverflowProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /github/home/build

# Include any dependencies generated for this target.
include lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/flags.make

lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/src/JsonReader.cpp.o: lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/flags.make
lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/src/JsonReader.cpp.o: /__w/OverflowProject/OverflowProject/lib/Parser/lib/JsonReader/src/JsonReader.cpp
lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/src/JsonReader.cpp.o: lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/github/home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/src/JsonReader.cpp.o"
	cd /github/home/build/lib/Parser/lib/JsonReader && /usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/src/JsonReader.cpp.o -MF CMakeFiles/JsonReader.dir/src/JsonReader.cpp.o.d -o CMakeFiles/JsonReader.dir/src/JsonReader.cpp.o -c /__w/OverflowProject/OverflowProject/lib/Parser/lib/JsonReader/src/JsonReader.cpp

lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/src/JsonReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JsonReader.dir/src/JsonReader.cpp.i"
	cd /github/home/build/lib/Parser/lib/JsonReader && /usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /__w/OverflowProject/OverflowProject/lib/Parser/lib/JsonReader/src/JsonReader.cpp > CMakeFiles/JsonReader.dir/src/JsonReader.cpp.i

lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/src/JsonReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JsonReader.dir/src/JsonReader.cpp.s"
	cd /github/home/build/lib/Parser/lib/JsonReader && /usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /__w/OverflowProject/OverflowProject/lib/Parser/lib/JsonReader/src/JsonReader.cpp -o CMakeFiles/JsonReader.dir/src/JsonReader.cpp.s

# Object files for target JsonReader
JsonReader_OBJECTS = \
"CMakeFiles/JsonReader.dir/src/JsonReader.cpp.o"

# External object files for target JsonReader
JsonReader_EXTERNAL_OBJECTS =

lib/Parser/lib/JsonReader/libJsonReader.a: lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/src/JsonReader.cpp.o
lib/Parser/lib/JsonReader/libJsonReader.a: lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/build.make
lib/Parser/lib/JsonReader/libJsonReader.a: lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/github/home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libJsonReader.a"
	cd /github/home/build/lib/Parser/lib/JsonReader && $(CMAKE_COMMAND) -P CMakeFiles/JsonReader.dir/cmake_clean_target.cmake
	cd /github/home/build/lib/Parser/lib/JsonReader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JsonReader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/build: lib/Parser/lib/JsonReader/libJsonReader.a
.PHONY : lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/build

lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/clean:
	cd /github/home/build/lib/Parser/lib/JsonReader && $(CMAKE_COMMAND) -P CMakeFiles/JsonReader.dir/cmake_clean.cmake
.PHONY : lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/clean

lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/depend:
	cd /github/home/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /__w/OverflowProject/OverflowProject /__w/OverflowProject/OverflowProject/lib/Parser/lib/JsonReader /github/home/build /github/home/build/lib/Parser/lib/JsonReader /github/home/build/lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Parser/lib/JsonReader/CMakeFiles/JsonReader.dir/depend

