# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/liying/桌面/Ex01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liying/桌面/Ex01/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/libex01.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/libex01.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/libex01.dir/flags.make

lib/CMakeFiles/libex01.dir/ex_01.cpp.o: lib/CMakeFiles/libex01.dir/flags.make
lib/CMakeFiles/libex01.dir/ex_01.cpp.o: ../lib/ex_01.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liying/桌面/Ex01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/libex01.dir/ex_01.cpp.o"
	cd /home/liying/桌面/Ex01/build/lib && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libex01.dir/ex_01.cpp.o -c /home/liying/桌面/Ex01/lib/ex_01.cpp

lib/CMakeFiles/libex01.dir/ex_01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libex01.dir/ex_01.cpp.i"
	cd /home/liying/桌面/Ex01/build/lib && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liying/桌面/Ex01/lib/ex_01.cpp > CMakeFiles/libex01.dir/ex_01.cpp.i

lib/CMakeFiles/libex01.dir/ex_01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libex01.dir/ex_01.cpp.s"
	cd /home/liying/桌面/Ex01/build/lib && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liying/桌面/Ex01/lib/ex_01.cpp -o CMakeFiles/libex01.dir/ex_01.cpp.s

lib/CMakeFiles/libex01.dir/ex_01.cpp.o.requires:

.PHONY : lib/CMakeFiles/libex01.dir/ex_01.cpp.o.requires

lib/CMakeFiles/libex01.dir/ex_01.cpp.o.provides: lib/CMakeFiles/libex01.dir/ex_01.cpp.o.requires
	$(MAKE) -f lib/CMakeFiles/libex01.dir/build.make lib/CMakeFiles/libex01.dir/ex_01.cpp.o.provides.build
.PHONY : lib/CMakeFiles/libex01.dir/ex_01.cpp.o.provides

lib/CMakeFiles/libex01.dir/ex_01.cpp.o.provides.build: lib/CMakeFiles/libex01.dir/ex_01.cpp.o


# Object files for target libex01
libex01_OBJECTS = \
"CMakeFiles/libex01.dir/ex_01.cpp.o"

# External object files for target libex01
libex01_EXTERNAL_OBJECTS =

lib/liblibex01.a: lib/CMakeFiles/libex01.dir/ex_01.cpp.o
lib/liblibex01.a: lib/CMakeFiles/libex01.dir/build.make
lib/liblibex01.a: lib/CMakeFiles/libex01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liying/桌面/Ex01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblibex01.a"
	cd /home/liying/桌面/Ex01/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/libex01.dir/cmake_clean_target.cmake
	cd /home/liying/桌面/Ex01/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libex01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/libex01.dir/build: lib/liblibex01.a

.PHONY : lib/CMakeFiles/libex01.dir/build

lib/CMakeFiles/libex01.dir/requires: lib/CMakeFiles/libex01.dir/ex_01.cpp.o.requires

.PHONY : lib/CMakeFiles/libex01.dir/requires

lib/CMakeFiles/libex01.dir/clean:
	cd /home/liying/桌面/Ex01/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/libex01.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/libex01.dir/clean

lib/CMakeFiles/libex01.dir/depend:
	cd /home/liying/桌面/Ex01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liying/桌面/Ex01 /home/liying/桌面/Ex01/lib /home/liying/桌面/Ex01/build /home/liying/桌面/Ex01/build/lib /home/liying/桌面/Ex01/build/lib/CMakeFiles/libex01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/libex01.dir/depend

