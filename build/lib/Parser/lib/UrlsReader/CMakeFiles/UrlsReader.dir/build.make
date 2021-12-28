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
include lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/flags.make

lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.o: lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/flags.make
lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.o: /__w/OverflowProject/OverflowProject/lib/Parser/lib/UrlsReader/src/UrlsReader.cpp
lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.o: lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/github/home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.o"
	cd /github/home/build/lib/Parser/lib/UrlsReader && /usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.o -MF CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.o.d -o CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.o -c /__w/OverflowProject/OverflowProject/lib/Parser/lib/UrlsReader/src/UrlsReader.cpp

lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.i"
	cd /github/home/build/lib/Parser/lib/UrlsReader && /usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /__w/OverflowProject/OverflowProject/lib/Parser/lib/UrlsReader/src/UrlsReader.cpp > CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.i

lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.s"
	cd /github/home/build/lib/Parser/lib/UrlsReader && /usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /__w/OverflowProject/OverflowProject/lib/Parser/lib/UrlsReader/src/UrlsReader.cpp -o CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.s

# Object files for target UrlsReader
UrlsReader_OBJECTS = \
"CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.o"

# External object files for target UrlsReader
UrlsReader_EXTERNAL_OBJECTS =

lib/Parser/lib/UrlsReader/libUrlsReader.a: lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/src/UrlsReader.cpp.o
lib/Parser/lib/UrlsReader/libUrlsReader.a: lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/build.make
lib/Parser/lib/UrlsReader/libUrlsReader.a: lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/github/home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libUrlsReader.a"
	cd /github/home/build/lib/Parser/lib/UrlsReader && $(CMAKE_COMMAND) -P CMakeFiles/UrlsReader.dir/cmake_clean_target.cmake
	cd /github/home/build/lib/Parser/lib/UrlsReader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UrlsReader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/build: lib/Parser/lib/UrlsReader/libUrlsReader.a
.PHONY : lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/build

lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/clean:
	cd /github/home/build/lib/Parser/lib/UrlsReader && $(CMAKE_COMMAND) -P CMakeFiles/UrlsReader.dir/cmake_clean.cmake
.PHONY : lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/clean

lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/depend:
	cd /github/home/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /__w/OverflowProject/OverflowProject /__w/OverflowProject/OverflowProject/lib/Parser/lib/UrlsReader /github/home/build /github/home/build/lib/Parser/lib/UrlsReader /github/home/build/lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Parser/lib/UrlsReader/CMakeFiles/UrlsReader.dir/depend

