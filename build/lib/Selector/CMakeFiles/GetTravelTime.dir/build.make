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
CMAKE_SOURCE_DIR = /home/justcrab/vscode/OverflowProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/justcrab/vscode/OverflowProject/build

# Include any dependencies generated for this target.
include lib/Selector/CMakeFiles/GetTravelTime.dir/depend.make

# Include the progress variables for this target.
include lib/Selector/CMakeFiles/GetTravelTime.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Selector/CMakeFiles/GetTravelTime.dir/flags.make

lib/Selector/CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.o: lib/Selector/CMakeFiles/GetTravelTime.dir/flags.make
lib/Selector/CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.o: ../lib/Selector/src/GetTravelTime.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justcrab/vscode/OverflowProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Selector/CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.o"
	cd /home/justcrab/vscode/OverflowProject/build/lib/Selector && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.o -c /home/justcrab/vscode/OverflowProject/lib/Selector/src/GetTravelTime.cpp

lib/Selector/CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.i"
	cd /home/justcrab/vscode/OverflowProject/build/lib/Selector && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justcrab/vscode/OverflowProject/lib/Selector/src/GetTravelTime.cpp > CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.i

lib/Selector/CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.s"
	cd /home/justcrab/vscode/OverflowProject/build/lib/Selector && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justcrab/vscode/OverflowProject/lib/Selector/src/GetTravelTime.cpp -o CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.s

# Object files for target GetTravelTime
GetTravelTime_OBJECTS = \
"CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.o"

# External object files for target GetTravelTime
GetTravelTime_EXTERNAL_OBJECTS =

lib/Selector/libGetTravelTime.a: lib/Selector/CMakeFiles/GetTravelTime.dir/src/GetTravelTime.cpp.o
lib/Selector/libGetTravelTime.a: lib/Selector/CMakeFiles/GetTravelTime.dir/build.make
lib/Selector/libGetTravelTime.a: lib/Selector/CMakeFiles/GetTravelTime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/justcrab/vscode/OverflowProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libGetTravelTime.a"
	cd /home/justcrab/vscode/OverflowProject/build/lib/Selector && $(CMAKE_COMMAND) -P CMakeFiles/GetTravelTime.dir/cmake_clean_target.cmake
	cd /home/justcrab/vscode/OverflowProject/build/lib/Selector && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GetTravelTime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/Selector/CMakeFiles/GetTravelTime.dir/build: lib/Selector/libGetTravelTime.a

.PHONY : lib/Selector/CMakeFiles/GetTravelTime.dir/build

lib/Selector/CMakeFiles/GetTravelTime.dir/clean:
	cd /home/justcrab/vscode/OverflowProject/build/lib/Selector && $(CMAKE_COMMAND) -P CMakeFiles/GetTravelTime.dir/cmake_clean.cmake
.PHONY : lib/Selector/CMakeFiles/GetTravelTime.dir/clean

lib/Selector/CMakeFiles/GetTravelTime.dir/depend:
	cd /home/justcrab/vscode/OverflowProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justcrab/vscode/OverflowProject /home/justcrab/vscode/OverflowProject/lib/Selector /home/justcrab/vscode/OverflowProject/build /home/justcrab/vscode/OverflowProject/build/lib/Selector /home/justcrab/vscode/OverflowProject/build/lib/Selector/CMakeFiles/GetTravelTime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Selector/CMakeFiles/GetTravelTime.dir/depend
