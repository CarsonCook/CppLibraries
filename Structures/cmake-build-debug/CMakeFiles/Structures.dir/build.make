# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\cookc\Desktop\Code\CppLibraries\Structures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\cookc\Desktop\Code\CppLibraries\Structures\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Structures.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Structures.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Structures.dir/flags.make

CMakeFiles/Structures.dir/main.cpp.obj: CMakeFiles/Structures.dir/flags.make
CMakeFiles/Structures.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cookc\Desktop\Code\CppLibraries\Structures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Structures.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Structures.dir\main.cpp.obj -c C:\Users\cookc\Desktop\Code\CppLibraries\Structures\main.cpp

CMakeFiles/Structures.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Structures.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cookc\Desktop\Code\CppLibraries\Structures\main.cpp > CMakeFiles\Structures.dir\main.cpp.i

CMakeFiles/Structures.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Structures.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cookc\Desktop\Code\CppLibraries\Structures\main.cpp -o CMakeFiles\Structures.dir\main.cpp.s

CMakeFiles/Structures.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Structures.dir/main.cpp.obj.requires

CMakeFiles/Structures.dir/main.cpp.obj.provides: CMakeFiles/Structures.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Structures.dir\build.make CMakeFiles/Structures.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Structures.dir/main.cpp.obj.provides

CMakeFiles/Structures.dir/main.cpp.obj.provides.build: CMakeFiles/Structures.dir/main.cpp.obj


CMakeFiles/Structures.dir/util.cpp.obj: CMakeFiles/Structures.dir/flags.make
CMakeFiles/Structures.dir/util.cpp.obj: ../util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cookc\Desktop\Code\CppLibraries\Structures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Structures.dir/util.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Structures.dir\util.cpp.obj -c C:\Users\cookc\Desktop\Code\CppLibraries\Structures\util.cpp

CMakeFiles/Structures.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Structures.dir/util.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cookc\Desktop\Code\CppLibraries\Structures\util.cpp > CMakeFiles\Structures.dir\util.cpp.i

CMakeFiles/Structures.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Structures.dir/util.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cookc\Desktop\Code\CppLibraries\Structures\util.cpp -o CMakeFiles\Structures.dir\util.cpp.s

CMakeFiles/Structures.dir/util.cpp.obj.requires:

.PHONY : CMakeFiles/Structures.dir/util.cpp.obj.requires

CMakeFiles/Structures.dir/util.cpp.obj.provides: CMakeFiles/Structures.dir/util.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Structures.dir\build.make CMakeFiles/Structures.dir/util.cpp.obj.provides.build
.PHONY : CMakeFiles/Structures.dir/util.cpp.obj.provides

CMakeFiles/Structures.dir/util.cpp.obj.provides.build: CMakeFiles/Structures.dir/util.cpp.obj


# Object files for target Structures
Structures_OBJECTS = \
"CMakeFiles/Structures.dir/main.cpp.obj" \
"CMakeFiles/Structures.dir/util.cpp.obj"

# External object files for target Structures
Structures_EXTERNAL_OBJECTS =

Structures.exe: CMakeFiles/Structures.dir/main.cpp.obj
Structures.exe: CMakeFiles/Structures.dir/util.cpp.obj
Structures.exe: CMakeFiles/Structures.dir/build.make
Structures.exe: CMakeFiles/Structures.dir/linklibs.rsp
Structures.exe: CMakeFiles/Structures.dir/objects1.rsp
Structures.exe: CMakeFiles/Structures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\cookc\Desktop\Code\CppLibraries\Structures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Structures.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Structures.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Structures.dir/build: Structures.exe

.PHONY : CMakeFiles/Structures.dir/build

CMakeFiles/Structures.dir/requires: CMakeFiles/Structures.dir/main.cpp.obj.requires
CMakeFiles/Structures.dir/requires: CMakeFiles/Structures.dir/util.cpp.obj.requires

.PHONY : CMakeFiles/Structures.dir/requires

CMakeFiles/Structures.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Structures.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Structures.dir/clean

CMakeFiles/Structures.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\cookc\Desktop\Code\CppLibraries\Structures C:\Users\cookc\Desktop\Code\CppLibraries\Structures C:\Users\cookc\Desktop\Code\CppLibraries\Structures\cmake-build-debug C:\Users\cookc\Desktop\Code\CppLibraries\Structures\cmake-build-debug C:\Users\cookc\Desktop\Code\CppLibraries\Structures\cmake-build-debug\CMakeFiles\Structures.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Structures.dir/depend
