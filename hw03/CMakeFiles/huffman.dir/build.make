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
CMAKE_SOURCE_DIR = "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105"

# Include any dependencies generated for this target.
include CMakeFiles/huffman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/huffman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/huffman.dir/flags.make

CMakeFiles/huffman.dir/src/minheap.c.o: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/src/minheap.c.o: src/minheap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/huffman.dir/src/minheap.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/huffman.dir/src/minheap.c.o   -c "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105/src/minheap.c"

CMakeFiles/huffman.dir/src/minheap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/huffman.dir/src/minheap.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105/src/minheap.c" > CMakeFiles/huffman.dir/src/minheap.c.i

CMakeFiles/huffman.dir/src/minheap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/huffman.dir/src/minheap.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105/src/minheap.c" -o CMakeFiles/huffman.dir/src/minheap.c.s

CMakeFiles/huffman.dir/src/huffman.c.o: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/src/huffman.c.o: src/huffman.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/huffman.dir/src/huffman.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/huffman.dir/src/huffman.c.o   -c "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105/src/huffman.c"

CMakeFiles/huffman.dir/src/huffman.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/huffman.dir/src/huffman.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105/src/huffman.c" > CMakeFiles/huffman.dir/src/huffman.c.i

CMakeFiles/huffman.dir/src/huffman.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/huffman.dir/src/huffman.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105/src/huffman.c" -o CMakeFiles/huffman.dir/src/huffman.c.s

# Object files for target huffman
huffman_OBJECTS = \
"CMakeFiles/huffman.dir/src/minheap.c.o" \
"CMakeFiles/huffman.dir/src/huffman.c.o"

# External object files for target huffman
huffman_EXTERNAL_OBJECTS =

huffman: CMakeFiles/huffman.dir/src/minheap.c.o
huffman: CMakeFiles/huffman.dir/src/huffman.c.o
huffman: CMakeFiles/huffman.dir/build.make
huffman: CMakeFiles/huffman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable huffman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/huffman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/huffman.dir/build: huffman

.PHONY : CMakeFiles/huffman.dir/build

CMakeFiles/huffman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/huffman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/huffman.dir/clean

CMakeFiles/huffman.dir/depend:
	cd "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105" "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105" "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105" "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105" "/Users/jiangyukun/Desktop/Computer System Organization Fall2019/Assignment 03/hw03-jiang19990105/CMakeFiles/huffman.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/huffman.dir/depend
