# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "D:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\GithubProject\Data-Structure-C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\GithubProject\Data-Structure-C++\cmake-build-debug

# Include any dependencies generated for this target.
include include/CMakeFiles/Hello.dir/depend.make

# Include the progress variables for this target.
include include/CMakeFiles/Hello.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/Hello.dir/flags.make

include/CMakeFiles/Hello.dir/hello.cpp.obj: include/CMakeFiles/Hello.dir/flags.make
include/CMakeFiles/Hello.dir/hello.cpp.obj: ../include/hello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\GithubProject\Data-Structure-C++\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/CMakeFiles/Hello.dir/hello.cpp.obj"
	cd /d E:\GithubProject\Data-Structure-C++\cmake-build-debug\include && D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Hello.dir\hello.cpp.obj -c E:\GithubProject\Data-Structure-C++\include\hello.cpp

include/CMakeFiles/Hello.dir/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hello.dir/hello.cpp.i"
	cd /d E:\GithubProject\Data-Structure-C++\cmake-build-debug\include && D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\GithubProject\Data-Structure-C++\include\hello.cpp > CMakeFiles\Hello.dir\hello.cpp.i

include/CMakeFiles/Hello.dir/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hello.dir/hello.cpp.s"
	cd /d E:\GithubProject\Data-Structure-C++\cmake-build-debug\include && D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\GithubProject\Data-Structure-C++\include\hello.cpp -o CMakeFiles\Hello.dir\hello.cpp.s

# Object files for target Hello
Hello_OBJECTS = \
"CMakeFiles/Hello.dir/hello.cpp.obj"

# External object files for target Hello
Hello_EXTERNAL_OBJECTS =

include/libHello.a: include/CMakeFiles/Hello.dir/hello.cpp.obj
include/libHello.a: include/CMakeFiles/Hello.dir/build.make
include/libHello.a: include/CMakeFiles/Hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\GithubProject\Data-Structure-C++\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libHello.a"
	cd /d E:\GithubProject\Data-Structure-C++\cmake-build-debug\include && $(CMAKE_COMMAND) -P CMakeFiles\Hello.dir\cmake_clean_target.cmake
	cd /d E:\GithubProject\Data-Structure-C++\cmake-build-debug\include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Hello.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/Hello.dir/build: include/libHello.a

.PHONY : include/CMakeFiles/Hello.dir/build

include/CMakeFiles/Hello.dir/clean:
	cd /d E:\GithubProject\Data-Structure-C++\cmake-build-debug\include && $(CMAKE_COMMAND) -P CMakeFiles\Hello.dir\cmake_clean.cmake
.PHONY : include/CMakeFiles/Hello.dir/clean

include/CMakeFiles/Hello.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\GithubProject\Data-Structure-C++ E:\GithubProject\Data-Structure-C++\include E:\GithubProject\Data-Structure-C++\cmake-build-debug E:\GithubProject\Data-Structure-C++\cmake-build-debug\include E:\GithubProject\Data-Structure-C++\cmake-build-debug\include\CMakeFiles\Hello.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/Hello.dir/depend

