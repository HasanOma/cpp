# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\hassa\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3739.54\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\hassa\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3739.54\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/oving7b.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/oving7b.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/oving7b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/oving7b.dir/flags.make

CMakeFiles/oving7b.dir/b.cpp.obj: CMakeFiles/oving7b.dir/flags.make
CMakeFiles/oving7b.dir/b.cpp.obj: ../b.cpp
CMakeFiles/oving7b.dir/b.cpp.obj: CMakeFiles/oving7b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/oving7b.dir/b.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/oving7b.dir/b.cpp.obj -MF CMakeFiles\oving7b.dir\b.cpp.obj.d -o CMakeFiles\oving7b.dir\b.cpp.obj -c C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7\b.cpp

CMakeFiles/oving7b.dir/b.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oving7b.dir/b.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7\b.cpp > CMakeFiles\oving7b.dir\b.cpp.i

CMakeFiles/oving7b.dir/b.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oving7b.dir/b.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7\b.cpp -o CMakeFiles\oving7b.dir\b.cpp.s

# Object files for target oving7b
oving7b_OBJECTS = \
"CMakeFiles/oving7b.dir/b.cpp.obj"

# External object files for target oving7b
oving7b_EXTERNAL_OBJECTS =

oving7b.exe: CMakeFiles/oving7b.dir/b.cpp.obj
oving7b.exe: CMakeFiles/oving7b.dir/build.make
oving7b.exe: CMakeFiles/oving7b.dir/linklibs.rsp
oving7b.exe: CMakeFiles/oving7b.dir/objects1.rsp
oving7b.exe: CMakeFiles/oving7b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable oving7b.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\oving7b.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/oving7b.dir/build: oving7b.exe
.PHONY : CMakeFiles/oving7b.dir/build

CMakeFiles/oving7b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\oving7b.dir\cmake_clean.cmake
.PHONY : CMakeFiles/oving7b.dir/clean

CMakeFiles/oving7b.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7 C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7 C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7\cmake-build-debug C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7\cmake-build-debug C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving7\cmake-build-debug\CMakeFiles\oving7b.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/oving7b.dir/depend
