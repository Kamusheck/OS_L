# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /workspaces/OS_L

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/OS_L/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/lab1_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/lab1_test.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/lab1_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/lab1_test.dir/flags.make

tests/CMakeFiles/lab1_test.dir/lab1_test.cpp.o: tests/CMakeFiles/lab1_test.dir/flags.make
tests/CMakeFiles/lab1_test.dir/lab1_test.cpp.o: /workspaces/OS_L/tests/lab1_test.cpp
tests/CMakeFiles/lab1_test.dir/lab1_test.cpp.o: tests/CMakeFiles/lab1_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/OS_L/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/lab1_test.dir/lab1_test.cpp.o"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/lab1_test.dir/lab1_test.cpp.o -MF CMakeFiles/lab1_test.dir/lab1_test.cpp.o.d -o CMakeFiles/lab1_test.dir/lab1_test.cpp.o -c /workspaces/OS_L/tests/lab1_test.cpp

tests/CMakeFiles/lab1_test.dir/lab1_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1_test.dir/lab1_test.cpp.i"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/OS_L/tests/lab1_test.cpp > CMakeFiles/lab1_test.dir/lab1_test.cpp.i

tests/CMakeFiles/lab1_test.dir/lab1_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1_test.dir/lab1_test.cpp.s"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/OS_L/tests/lab1_test.cpp -o CMakeFiles/lab1_test.dir/lab1_test.cpp.s

tests/CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.o: tests/CMakeFiles/lab1_test.dir/flags.make
tests/CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.o: /workspaces/OS_L/lab1/src/parent.cpp
tests/CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.o: tests/CMakeFiles/lab1_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/OS_L/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.o"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.o -MF CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.o.d -o CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.o -c /workspaces/OS_L/lab1/src/parent.cpp

tests/CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.i"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/OS_L/lab1/src/parent.cpp > CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.i

tests/CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.s"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/OS_L/lab1/src/parent.cpp -o CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.s

tests/CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.o: tests/CMakeFiles/lab1_test.dir/flags.make
tests/CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.o: /workspaces/OS_L/lab1/src/commonchild.cpp
tests/CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.o: tests/CMakeFiles/lab1_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/OS_L/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.o"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.o -MF CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.o.d -o CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.o -c /workspaces/OS_L/lab1/src/commonchild.cpp

tests/CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.i"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/OS_L/lab1/src/commonchild.cpp > CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.i

tests/CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.s"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/OS_L/lab1/src/commonchild.cpp -o CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.s

tests/CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.o: tests/CMakeFiles/lab1_test.dir/flags.make
tests/CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.o: /workspaces/OS_L/lab1/src/child1.cpp
tests/CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.o: tests/CMakeFiles/lab1_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/OS_L/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tests/CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.o"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.o -MF CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.o.d -o CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.o -c /workspaces/OS_L/lab1/src/child1.cpp

tests/CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.i"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/OS_L/lab1/src/child1.cpp > CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.i

tests/CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.s"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/OS_L/lab1/src/child1.cpp -o CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.s

tests/CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.o: tests/CMakeFiles/lab1_test.dir/flags.make
tests/CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.o: /workspaces/OS_L/lab1/src/child2.cpp
tests/CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.o: tests/CMakeFiles/lab1_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/OS_L/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object tests/CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.o"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.o -MF CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.o.d -o CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.o -c /workspaces/OS_L/lab1/src/child2.cpp

tests/CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.i"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/OS_L/lab1/src/child2.cpp > CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.i

tests/CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.s"
	cd /workspaces/OS_L/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/OS_L/lab1/src/child2.cpp -o CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.s

# Object files for target lab1_test
lab1_test_OBJECTS = \
"CMakeFiles/lab1_test.dir/lab1_test.cpp.o" \
"CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.o" \
"CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.o" \
"CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.o" \
"CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.o"

# External object files for target lab1_test
lab1_test_EXTERNAL_OBJECTS =

tests/lab1_test: tests/CMakeFiles/lab1_test.dir/lab1_test.cpp.o
tests/lab1_test: tests/CMakeFiles/lab1_test.dir/__/lab1/src/parent.cpp.o
tests/lab1_test: tests/CMakeFiles/lab1_test.dir/__/lab1/src/commonchild.cpp.o
tests/lab1_test: tests/CMakeFiles/lab1_test.dir/__/lab1/src/child1.cpp.o
tests/lab1_test: tests/CMakeFiles/lab1_test.dir/__/lab1/src/child2.cpp.o
tests/lab1_test: tests/CMakeFiles/lab1_test.dir/build.make
tests/lab1_test: lib/libgtest.a
tests/lab1_test: lib/libgtest_main.a
tests/lab1_test: lib/libgtest.a
tests/lab1_test: tests/CMakeFiles/lab1_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/OS_L/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable lab1_test"
	cd /workspaces/OS_L/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab1_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/lab1_test.dir/build: tests/lab1_test
.PHONY : tests/CMakeFiles/lab1_test.dir/build

tests/CMakeFiles/lab1_test.dir/clean:
	cd /workspaces/OS_L/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/lab1_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/lab1_test.dir/clean

tests/CMakeFiles/lab1_test.dir/depend:
	cd /workspaces/OS_L/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/OS_L /workspaces/OS_L/tests /workspaces/OS_L/build /workspaces/OS_L/build/tests /workspaces/OS_L/build/tests/CMakeFiles/lab1_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/lab1_test.dir/depend

