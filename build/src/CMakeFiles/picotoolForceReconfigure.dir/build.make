# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/felipe/Desktop/FreeRTOS/SafeDriverRTOS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/felipe/Desktop/FreeRTOS/SafeDriverRTOS/build

# Utility rule file for picotoolForceReconfigure.

# Include any custom commands dependencies for this target.
include src/CMakeFiles/picotoolForceReconfigure.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/picotoolForceReconfigure.dir/progress.make

src/CMakeFiles/picotoolForceReconfigure:
	cd /home/felipe/Desktop/FreeRTOS/SafeDriverRTOS/build/src && /usr/bin/cmake -E touch_nocreate /home/felipe/Desktop/FreeRTOS/SafeDriverRTOS/CMakeLists.txt

picotoolForceReconfigure: src/CMakeFiles/picotoolForceReconfigure
picotoolForceReconfigure: src/CMakeFiles/picotoolForceReconfigure.dir/build.make
.PHONY : picotoolForceReconfigure

# Rule to build all files generated by this target.
src/CMakeFiles/picotoolForceReconfigure.dir/build: picotoolForceReconfigure
.PHONY : src/CMakeFiles/picotoolForceReconfigure.dir/build

src/CMakeFiles/picotoolForceReconfigure.dir/clean:
	cd /home/felipe/Desktop/FreeRTOS/SafeDriverRTOS/build/src && $(CMAKE_COMMAND) -P CMakeFiles/picotoolForceReconfigure.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/picotoolForceReconfigure.dir/clean

src/CMakeFiles/picotoolForceReconfigure.dir/depend:
	cd /home/felipe/Desktop/FreeRTOS/SafeDriverRTOS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felipe/Desktop/FreeRTOS/SafeDriverRTOS /home/felipe/Desktop/FreeRTOS/SafeDriverRTOS/src /home/felipe/Desktop/FreeRTOS/SafeDriverRTOS/build /home/felipe/Desktop/FreeRTOS/SafeDriverRTOS/build/src /home/felipe/Desktop/FreeRTOS/SafeDriverRTOS/build/src/CMakeFiles/picotoolForceReconfigure.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/picotoolForceReconfigure.dir/depend

