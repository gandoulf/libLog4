# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/resse/work/libLog4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/resse/work/libLog4

# Include any dependencies generated for this target.
include CMakeFiles/Log4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Log4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Log4.dir/flags.make

CMakeFiles/Log4.dir/src/log4.cpp.o: CMakeFiles/Log4.dir/flags.make
CMakeFiles/Log4.dir/src/log4.cpp.o: src/log4.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/resse/work/libLog4/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Log4.dir/src/log4.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Log4.dir/src/log4.cpp.o -c /home/resse/work/libLog4/src/log4.cpp

CMakeFiles/Log4.dir/src/log4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Log4.dir/src/log4.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/resse/work/libLog4/src/log4.cpp > CMakeFiles/Log4.dir/src/log4.cpp.i

CMakeFiles/Log4.dir/src/log4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Log4.dir/src/log4.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/resse/work/libLog4/src/log4.cpp -o CMakeFiles/Log4.dir/src/log4.cpp.s

CMakeFiles/Log4.dir/src/log4.cpp.o.requires:
.PHONY : CMakeFiles/Log4.dir/src/log4.cpp.o.requires

CMakeFiles/Log4.dir/src/log4.cpp.o.provides: CMakeFiles/Log4.dir/src/log4.cpp.o.requires
	$(MAKE) -f CMakeFiles/Log4.dir/build.make CMakeFiles/Log4.dir/src/log4.cpp.o.provides.build
.PHONY : CMakeFiles/Log4.dir/src/log4.cpp.o.provides

CMakeFiles/Log4.dir/src/log4.cpp.o.provides.build: CMakeFiles/Log4.dir/src/log4.cpp.o

# Object files for target Log4
Log4_OBJECTS = \
"CMakeFiles/Log4.dir/src/log4.cpp.o"

# External object files for target Log4
Log4_EXTERNAL_OBJECTS =

lib/libLog4.so: CMakeFiles/Log4.dir/src/log4.cpp.o
lib/libLog4.so: CMakeFiles/Log4.dir/build.make
lib/libLog4.so: CMakeFiles/Log4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library lib/libLog4.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Log4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Log4.dir/build: lib/libLog4.so
.PHONY : CMakeFiles/Log4.dir/build

CMakeFiles/Log4.dir/requires: CMakeFiles/Log4.dir/src/log4.cpp.o.requires
.PHONY : CMakeFiles/Log4.dir/requires

CMakeFiles/Log4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Log4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Log4.dir/clean

CMakeFiles/Log4.dir/depend:
	cd /home/resse/work/libLog4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/resse/work/libLog4 /home/resse/work/libLog4 /home/resse/work/libLog4 /home/resse/work/libLog4 /home/resse/work/libLog4/CMakeFiles/Log4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Log4.dir/depend

