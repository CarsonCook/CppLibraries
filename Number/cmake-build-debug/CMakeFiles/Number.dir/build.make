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
CMAKE_SOURCE_DIR = C:\Users\cookc\Desktop\Code\CppLibraries\Number

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\cookc\Desktop\Code\CppLibraries\Number\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Number.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Number.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Number.dir/flags.make

CMakeFiles/Number.dir/main.cpp.obj: CMakeFiles/Number.dir/flags.make
CMakeFiles/Number.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cookc\Desktop\Code\CppLibraries\Number\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Number.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Number.dir\main.cpp.obj -c C:\Users\cookc\Desktop\Code\CppLibraries\Number\main.cpp

CMakeFiles/Number.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Number.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cookc\Desktop\Code\CppLibraries\Number\main.cpp > CMakeFiles\Number.dir\main.cpp.i

CMakeFiles/Number.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Number.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cookc\Desktop\Code\CppLibraries\Number\main.cpp -o CMakeFiles\Number.dir\main.cpp.s

CMakeFiles/Number.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Number.dir/main.cpp.obj.requires

CMakeFiles/Number.dir/main.cpp.obj.provides: CMakeFiles/Number.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Number.dir\build.make CMakeFiles/Number.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Number.dir/main.cpp.obj.provides

CMakeFiles/Number.dir/main.cpp.obj.provides.build: CMakeFiles/Number.dir/main.cpp.obj


CMakeFiles/Number.dir/Number.cpp.obj: CMakeFiles/Number.dir/flags.make
CMakeFiles/Number.dir/Number.cpp.obj: ../Number.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cookc\Desktop\Code\CppLibraries\Number\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Number.dir/Number.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Number.dir\Number.cpp.obj -c C:\Users\cookc\Desktop\Code\CppLibraries\Number\Number.cpp

CMakeFiles/Number.dir/Number.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Number.dir/Number.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cookc\Desktop\Code\CppLibraries\Number\Number.cpp > CMakeFiles\Number.dir\Number.cpp.i

CMakeFiles/Number.dir/Number.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Number.dir/Number.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cookc\Desktop\Code\CppLibraries\Number\Number.cpp -o CMakeFiles\Number.dir\Number.cpp.s

CMakeFiles/Number.dir/Number.cpp.obj.requires:

.PHONY : CMakeFiles/Number.dir/Number.cpp.obj.requires

CMakeFiles/Number.dir/Number.cpp.obj.provides: CMakeFiles/Number.dir/Number.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Number.dir\build.make CMakeFiles/Number.dir/Number.cpp.obj.provides.build
.PHONY : CMakeFiles/Number.dir/Number.cpp.obj.provides

CMakeFiles/Number.dir/Number.cpp.obj.provides.build: CMakeFiles/Number.dir/Number.cpp.obj


CMakeFiles/Number.dir/NumberOperators.cpp.obj: CMakeFiles/Number.dir/flags.make
CMakeFiles/Number.dir/NumberOperators.cpp.obj: ../NumberOperators.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cookc\Desktop\Code\CppLibraries\Number\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Number.dir/NumberOperators.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Number.dir\NumberOperators.cpp.obj -c C:\Users\cookc\Desktop\Code\CppLibraries\Number\NumberOperators.cpp

CMakeFiles/Number.dir/NumberOperators.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Number.dir/NumberOperators.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cookc\Desktop\Code\CppLibraries\Number\NumberOperators.cpp > CMakeFiles\Number.dir\NumberOperators.cpp.i

CMakeFiles/Number.dir/NumberOperators.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Number.dir/NumberOperators.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cookc\Desktop\Code\CppLibraries\Number\NumberOperators.cpp -o CMakeFiles\Number.dir\NumberOperators.cpp.s

CMakeFiles/Number.dir/NumberOperators.cpp.obj.requires:

.PHONY : CMakeFiles/Number.dir/NumberOperators.cpp.obj.requires

CMakeFiles/Number.dir/NumberOperators.cpp.obj.provides: CMakeFiles/Number.dir/NumberOperators.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Number.dir\build.make CMakeFiles/Number.dir/NumberOperators.cpp.obj.provides.build
.PHONY : CMakeFiles/Number.dir/NumberOperators.cpp.obj.provides

CMakeFiles/Number.dir/NumberOperators.cpp.obj.provides.build: CMakeFiles/Number.dir/NumberOperators.cpp.obj


CMakeFiles/Number.dir/NumberExceptions.cpp.obj: CMakeFiles/Number.dir/flags.make
CMakeFiles/Number.dir/NumberExceptions.cpp.obj: ../NumberExceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cookc\Desktop\Code\CppLibraries\Number\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Number.dir/NumberExceptions.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Number.dir\NumberExceptions.cpp.obj -c C:\Users\cookc\Desktop\Code\CppLibraries\Number\NumberExceptions.cpp

CMakeFiles/Number.dir/NumberExceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Number.dir/NumberExceptions.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cookc\Desktop\Code\CppLibraries\Number\NumberExceptions.cpp > CMakeFiles\Number.dir\NumberExceptions.cpp.i

CMakeFiles/Number.dir/NumberExceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Number.dir/NumberExceptions.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cookc\Desktop\Code\CppLibraries\Number\NumberExceptions.cpp -o CMakeFiles\Number.dir\NumberExceptions.cpp.s

CMakeFiles/Number.dir/NumberExceptions.cpp.obj.requires:

.PHONY : CMakeFiles/Number.dir/NumberExceptions.cpp.obj.requires

CMakeFiles/Number.dir/NumberExceptions.cpp.obj.provides: CMakeFiles/Number.dir/NumberExceptions.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Number.dir\build.make CMakeFiles/Number.dir/NumberExceptions.cpp.obj.provides.build
.PHONY : CMakeFiles/Number.dir/NumberExceptions.cpp.obj.provides

CMakeFiles/Number.dir/NumberExceptions.cpp.obj.provides.build: CMakeFiles/Number.dir/NumberExceptions.cpp.obj


# Object files for target Number
Number_OBJECTS = \
"CMakeFiles/Number.dir/main.cpp.obj" \
"CMakeFiles/Number.dir/Number.cpp.obj" \
"CMakeFiles/Number.dir/NumberOperators.cpp.obj" \
"CMakeFiles/Number.dir/NumberExceptions.cpp.obj"

# External object files for target Number
Number_EXTERNAL_OBJECTS =

Number.exe: CMakeFiles/Number.dir/main.cpp.obj
Number.exe: CMakeFiles/Number.dir/Number.cpp.obj
Number.exe: CMakeFiles/Number.dir/NumberOperators.cpp.obj
Number.exe: CMakeFiles/Number.dir/NumberExceptions.cpp.obj
Number.exe: CMakeFiles/Number.dir/build.make
Number.exe: CMakeFiles/Number.dir/linklibs.rsp
Number.exe: CMakeFiles/Number.dir/objects1.rsp
Number.exe: CMakeFiles/Number.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\cookc\Desktop\Code\CppLibraries\Number\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Number.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Number.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Number.dir/build: Number.exe

.PHONY : CMakeFiles/Number.dir/build

CMakeFiles/Number.dir/requires: CMakeFiles/Number.dir/main.cpp.obj.requires
CMakeFiles/Number.dir/requires: CMakeFiles/Number.dir/Number.cpp.obj.requires
CMakeFiles/Number.dir/requires: CMakeFiles/Number.dir/NumberOperators.cpp.obj.requires
CMakeFiles/Number.dir/requires: CMakeFiles/Number.dir/NumberExceptions.cpp.obj.requires

.PHONY : CMakeFiles/Number.dir/requires

CMakeFiles/Number.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Number.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Number.dir/clean

CMakeFiles/Number.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\cookc\Desktop\Code\CppLibraries\Number C:\Users\cookc\Desktop\Code\CppLibraries\Number C:\Users\cookc\Desktop\Code\CppLibraries\Number\cmake-build-debug C:\Users\cookc\Desktop\Code\CppLibraries\Number\cmake-build-debug C:\Users\cookc\Desktop\Code\CppLibraries\Number\cmake-build-debug\CMakeFiles\Number.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Number.dir/depend

