# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/trisha/Desktop/nsu/oop/oop_git/Lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/trisha/Desktop/nsu/oop/oop_git/lab3/build

# Include any dependencies generated for this target.
include CMakeFiles/SoundProcessor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SoundProcessor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SoundProcessor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SoundProcessor.dir/flags.make

CMakeFiles/SoundProcessor.dir/src/main.cpp.o: CMakeFiles/SoundProcessor.dir/flags.make
CMakeFiles/SoundProcessor.dir/src/main.cpp.o: /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/main.cpp
CMakeFiles/SoundProcessor.dir/src/main.cpp.o: CMakeFiles/SoundProcessor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/trisha/Desktop/nsu/oop/oop_git/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SoundProcessor.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SoundProcessor.dir/src/main.cpp.o -MF CMakeFiles/SoundProcessor.dir/src/main.cpp.o.d -o CMakeFiles/SoundProcessor.dir/src/main.cpp.o -c /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/main.cpp

CMakeFiles/SoundProcessor.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SoundProcessor.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/main.cpp > CMakeFiles/SoundProcessor.dir/src/main.cpp.i

CMakeFiles/SoundProcessor.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SoundProcessor.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/main.cpp -o CMakeFiles/SoundProcessor.dir/src/main.cpp.s

CMakeFiles/SoundProcessor.dir/src/View.cpp.o: CMakeFiles/SoundProcessor.dir/flags.make
CMakeFiles/SoundProcessor.dir/src/View.cpp.o: /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/View.cpp
CMakeFiles/SoundProcessor.dir/src/View.cpp.o: CMakeFiles/SoundProcessor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/trisha/Desktop/nsu/oop/oop_git/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SoundProcessor.dir/src/View.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SoundProcessor.dir/src/View.cpp.o -MF CMakeFiles/SoundProcessor.dir/src/View.cpp.o.d -o CMakeFiles/SoundProcessor.dir/src/View.cpp.o -c /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/View.cpp

CMakeFiles/SoundProcessor.dir/src/View.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SoundProcessor.dir/src/View.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/View.cpp > CMakeFiles/SoundProcessor.dir/src/View.cpp.i

CMakeFiles/SoundProcessor.dir/src/View.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SoundProcessor.dir/src/View.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/View.cpp -o CMakeFiles/SoundProcessor.dir/src/View.cpp.s

CMakeFiles/SoundProcessor.dir/src/Config.cpp.o: CMakeFiles/SoundProcessor.dir/flags.make
CMakeFiles/SoundProcessor.dir/src/Config.cpp.o: /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Config.cpp
CMakeFiles/SoundProcessor.dir/src/Config.cpp.o: CMakeFiles/SoundProcessor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/trisha/Desktop/nsu/oop/oop_git/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SoundProcessor.dir/src/Config.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SoundProcessor.dir/src/Config.cpp.o -MF CMakeFiles/SoundProcessor.dir/src/Config.cpp.o.d -o CMakeFiles/SoundProcessor.dir/src/Config.cpp.o -c /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Config.cpp

CMakeFiles/SoundProcessor.dir/src/Config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SoundProcessor.dir/src/Config.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Config.cpp > CMakeFiles/SoundProcessor.dir/src/Config.cpp.i

CMakeFiles/SoundProcessor.dir/src/Config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SoundProcessor.dir/src/Config.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Config.cpp -o CMakeFiles/SoundProcessor.dir/src/Config.cpp.s

CMakeFiles/SoundProcessor.dir/src/Processor.cpp.o: CMakeFiles/SoundProcessor.dir/flags.make
CMakeFiles/SoundProcessor.dir/src/Processor.cpp.o: /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Processor.cpp
CMakeFiles/SoundProcessor.dir/src/Processor.cpp.o: CMakeFiles/SoundProcessor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/trisha/Desktop/nsu/oop/oop_git/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SoundProcessor.dir/src/Processor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SoundProcessor.dir/src/Processor.cpp.o -MF CMakeFiles/SoundProcessor.dir/src/Processor.cpp.o.d -o CMakeFiles/SoundProcessor.dir/src/Processor.cpp.o -c /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Processor.cpp

CMakeFiles/SoundProcessor.dir/src/Processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SoundProcessor.dir/src/Processor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Processor.cpp > CMakeFiles/SoundProcessor.dir/src/Processor.cpp.i

CMakeFiles/SoundProcessor.dir/src/Processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SoundProcessor.dir/src/Processor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Processor.cpp -o CMakeFiles/SoundProcessor.dir/src/Processor.cpp.s

CMakeFiles/SoundProcessor.dir/src/Context.cpp.o: CMakeFiles/SoundProcessor.dir/flags.make
CMakeFiles/SoundProcessor.dir/src/Context.cpp.o: /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Context.cpp
CMakeFiles/SoundProcessor.dir/src/Context.cpp.o: CMakeFiles/SoundProcessor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/trisha/Desktop/nsu/oop/oop_git/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SoundProcessor.dir/src/Context.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SoundProcessor.dir/src/Context.cpp.o -MF CMakeFiles/SoundProcessor.dir/src/Context.cpp.o.d -o CMakeFiles/SoundProcessor.dir/src/Context.cpp.o -c /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Context.cpp

CMakeFiles/SoundProcessor.dir/src/Context.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SoundProcessor.dir/src/Context.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Context.cpp > CMakeFiles/SoundProcessor.dir/src/Context.cpp.i

CMakeFiles/SoundProcessor.dir/src/Context.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SoundProcessor.dir/src/Context.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/Context.cpp -o CMakeFiles/SoundProcessor.dir/src/Context.cpp.s

CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.o: CMakeFiles/SoundProcessor.dir/flags.make
CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.o: /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/MuteConverter.cpp
CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.o: CMakeFiles/SoundProcessor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/trisha/Desktop/nsu/oop/oop_git/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.o -MF CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.o.d -o CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.o -c /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/MuteConverter.cpp

CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/MuteConverter.cpp > CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.i

CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/MuteConverter.cpp -o CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.s

CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.o: CMakeFiles/SoundProcessor.dir/flags.make
CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.o: /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/MixConverter.cpp
CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.o: CMakeFiles/SoundProcessor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/trisha/Desktop/nsu/oop/oop_git/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.o -MF CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.o.d -o CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.o -c /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/MixConverter.cpp

CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/MixConverter.cpp > CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.i

CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/MixConverter.cpp -o CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.s

CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.o: CMakeFiles/SoundProcessor.dir/flags.make
CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.o: /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/ReverseConverter.cpp
CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.o: CMakeFiles/SoundProcessor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/trisha/Desktop/nsu/oop/oop_git/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.o -MF CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.o.d -o CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.o -c /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/ReverseConverter.cpp

CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/ReverseConverter.cpp > CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.i

CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trisha/Desktop/nsu/oop/oop_git/Lab3/src/ReverseConverter.cpp -o CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.s

# Object files for target SoundProcessor
SoundProcessor_OBJECTS = \
"CMakeFiles/SoundProcessor.dir/src/main.cpp.o" \
"CMakeFiles/SoundProcessor.dir/src/View.cpp.o" \
"CMakeFiles/SoundProcessor.dir/src/Config.cpp.o" \
"CMakeFiles/SoundProcessor.dir/src/Processor.cpp.o" \
"CMakeFiles/SoundProcessor.dir/src/Context.cpp.o" \
"CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.o" \
"CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.o" \
"CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.o"

# External object files for target SoundProcessor
SoundProcessor_EXTERNAL_OBJECTS =

SoundProcessor: CMakeFiles/SoundProcessor.dir/src/main.cpp.o
SoundProcessor: CMakeFiles/SoundProcessor.dir/src/View.cpp.o
SoundProcessor: CMakeFiles/SoundProcessor.dir/src/Config.cpp.o
SoundProcessor: CMakeFiles/SoundProcessor.dir/src/Processor.cpp.o
SoundProcessor: CMakeFiles/SoundProcessor.dir/src/Context.cpp.o
SoundProcessor: CMakeFiles/SoundProcessor.dir/src/MuteConverter.cpp.o
SoundProcessor: CMakeFiles/SoundProcessor.dir/src/MixConverter.cpp.o
SoundProcessor: CMakeFiles/SoundProcessor.dir/src/ReverseConverter.cpp.o
SoundProcessor: CMakeFiles/SoundProcessor.dir/build.make
SoundProcessor: CMakeFiles/SoundProcessor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/trisha/Desktop/nsu/oop/oop_git/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable SoundProcessor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SoundProcessor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SoundProcessor.dir/build: SoundProcessor
.PHONY : CMakeFiles/SoundProcessor.dir/build

CMakeFiles/SoundProcessor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SoundProcessor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SoundProcessor.dir/clean

CMakeFiles/SoundProcessor.dir/depend:
	cd /Users/trisha/Desktop/nsu/oop/oop_git/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/trisha/Desktop/nsu/oop/oop_git/Lab3 /Users/trisha/Desktop/nsu/oop/oop_git/Lab3 /Users/trisha/Desktop/nsu/oop/oop_git/lab3/build /Users/trisha/Desktop/nsu/oop/oop_git/lab3/build /Users/trisha/Desktop/nsu/oop/oop_git/lab3/build/CMakeFiles/SoundProcessor.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SoundProcessor.dir/depend

