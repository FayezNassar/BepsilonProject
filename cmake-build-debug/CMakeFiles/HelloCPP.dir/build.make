# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "C:\Users\Yossif\AppData\Roaming\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Yossif\AppData\Roaming\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Yossif\ClionProjects\BepsilonProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Yossif\ClionProjects\BepsilonProject\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HelloCPP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HelloCPP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HelloCPP.dir/flags.make

CMakeFiles/HelloCPP.dir/main.cpp.obj: CMakeFiles/HelloCPP.dir/flags.make
CMakeFiles/HelloCPP.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Yossif\ClionProjects\BepsilonProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HelloCPP.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\HelloCPP.dir\main.cpp.obj -c C:\Users\Yossif\ClionProjects\BepsilonProject\main.cpp

CMakeFiles/HelloCPP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloCPP.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Yossif\ClionProjects\BepsilonProject\main.cpp > CMakeFiles\HelloCPP.dir\main.cpp.i

CMakeFiles/HelloCPP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloCPP.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Yossif\ClionProjects\BepsilonProject\main.cpp -o CMakeFiles\HelloCPP.dir\main.cpp.s

CMakeFiles/HelloCPP.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/HelloCPP.dir/main.cpp.obj.requires

CMakeFiles/HelloCPP.dir/main.cpp.obj.provides: CMakeFiles/HelloCPP.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\HelloCPP.dir\build.make CMakeFiles/HelloCPP.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/HelloCPP.dir/main.cpp.obj.provides

CMakeFiles/HelloCPP.dir/main.cpp.obj.provides.build: CMakeFiles/HelloCPP.dir/main.cpp.obj


# Object files for target HelloCPP
HelloCPP_OBJECTS = \
"CMakeFiles/HelloCPP.dir/main.cpp.obj"

# External object files for target HelloCPP
HelloCPP_EXTERNAL_OBJECTS =

HelloCPP.exe: CMakeFiles/HelloCPP.dir/main.cpp.obj
HelloCPP.exe: CMakeFiles/HelloCPP.dir/build.make
HelloCPP.exe: CMakeFiles/HelloCPP.dir/linklibs.rsp
HelloCPP.exe: CMakeFiles/HelloCPP.dir/objects1.rsp
HelloCPP.exe: CMakeFiles/HelloCPP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Yossif\ClionProjects\BepsilonProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HelloCPP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HelloCPP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HelloCPP.dir/build: HelloCPP.exe

.PHONY : CMakeFiles/HelloCPP.dir/build

CMakeFiles/HelloCPP.dir/requires: CMakeFiles/HelloCPP.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/HelloCPP.dir/requires

CMakeFiles/HelloCPP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HelloCPP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HelloCPP.dir/clean

CMakeFiles/HelloCPP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Yossif\ClionProjects\BepsilonProject C:\Users\Yossif\ClionProjects\BepsilonProject C:\Users\Yossif\ClionProjects\BepsilonProject\cmake-build-debug C:\Users\Yossif\ClionProjects\BepsilonProject\cmake-build-debug C:\Users\Yossif\ClionProjects\BepsilonProject\cmake-build-debug\CMakeFiles\HelloCPP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HelloCPP.dir/depend

