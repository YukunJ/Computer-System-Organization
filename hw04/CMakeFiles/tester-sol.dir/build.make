# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105"

# Include any dependencies generated for this target.
include CMakeFiles/tester-sol.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tester-sol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tester-sol.dir/flags.make

# Object files for target tester-sol
tester__sol_OBJECTS =

# External object files for target tester-sol
tester__sol_EXTERNAL_OBJECTS = \
"/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105/objs-mac/tester.o" \
"/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105/objs-mac/ex1_sol.o" \
"/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105/objs-mac/ex2_sol.o" \
"/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105/objs-mac/ex3_sol.o" \
"/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105/objs-mac/ex4_sol.o" \
"/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105/objs-mac/ex5_sol.o"

tester-sol: objs-mac/tester.o
tester-sol: objs-mac/ex1_sol.o
tester-sol: objs-mac/ex2_sol.o
tester-sol: objs-mac/ex3_sol.o
tester-sol: objs-mac/ex4_sol.o
tester-sol: objs-mac/ex5_sol.o
tester-sol: CMakeFiles/tester-sol.dir/build.make
tester-sol: CMakeFiles/tester-sol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Linking C executable tester-sol"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tester-sol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tester-sol.dir/build: tester-sol

.PHONY : CMakeFiles/tester-sol.dir/build

CMakeFiles/tester-sol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tester-sol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tester-sol.dir/clean

CMakeFiles/tester-sol.dir/depend:
	cd "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105" "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105" "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105" "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105" "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 4/hw04-jiang19990105/CMakeFiles/tester-sol.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tester-sol.dir/depend

