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
CMAKE_SOURCE_DIR = C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/oving24.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/oving24.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/oving24.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/oving24.dir/flags.make

CMakeFiles/oving24.dir/oppg4.cpp.obj: CMakeFiles/oving24.dir/flags.make
CMakeFiles/oving24.dir/oppg4.cpp.obj: ../oppg4.cpp
CMakeFiles/oving24.dir/oppg4.cpp.obj: CMakeFiles/oving24.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/oving24.dir/oppg4.cpp.obj"
	C:\x86_64-8.1.0-release-win32-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/oving24.dir/oppg4.cpp.obj -MF CMakeFiles\oving24.dir\oppg4.cpp.obj.d -o CMakeFiles\oving24.dir\oppg4.cpp.obj -c C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2\oppg4.cpp

CMakeFiles/oving24.dir/oppg4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oving24.dir/oppg4.cpp.i"
	C:\x86_64-8.1.0-release-win32-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2\oppg4.cpp > CMakeFiles\oving24.dir\oppg4.cpp.i

CMakeFiles/oving24.dir/oppg4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oving24.dir/oppg4.cpp.s"
	C:\x86_64-8.1.0-release-win32-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2\oppg4.cpp -o CMakeFiles\oving24.dir\oppg4.cpp.s

# Object files for target oving24
oving24_OBJECTS = \
"CMakeFiles/oving24.dir/oppg4.cpp.obj"

# External object files for target oving24
oving24_EXTERNAL_OBJECTS =

oving24.exe: CMakeFiles/oving24.dir/oppg4.cpp.obj
oving24.exe: CMakeFiles/oving24.dir/build.make
oving24.exe: CMakeFiles/oving24.dir/linklibs.rsp
oving24.exe: CMakeFiles/oving24.dir/objects1.rsp
oving24.exe: CMakeFiles/oving24.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable oving24.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\oving24.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/oving24.dir/build: oving24.exe
.PHONY : CMakeFiles/oving24.dir/build

CMakeFiles/oving24.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\oving24.dir\cmake_clean.cmake
.PHONY : CMakeFiles/oving24.dir/clean

CMakeFiles/oving24.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2 C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2 C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2\cmake-build-debug C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2\cmake-build-debug C:\Users\hassa\NTNU.Data\3aar\1.sem\cpp\ovinger\oving2\cmake-build-debug\CMakeFiles\oving24.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/oving24.dir/depend
