# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/misha/progs/sphere_2020/afina

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/misha/progs/sphere_2020/afina

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test

.PHONY : test/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/misha/progs/sphere_2020/afina/CMakeFiles /home/misha/progs/sphere_2020/afina/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/misha/progs/sphere_2020/afina/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) -f third-party/googletest-release-1.8.0/googlemock/CMakeFiles/gmock_main.dir/build.make third-party/googletest-release-1.8.0/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) -f third-party/googletest-release-1.8.0/googlemock/CMakeFiles/gmock.dir/build.make third-party/googletest-release-1.8.0/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) -f third-party/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest_main.dir/build.make third-party/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) -f third-party/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/build.make third-party/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

#=============================================================================
# Target rules for targets named ExperimentalBuild

# Build rule for target.
ExperimentalBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalBuild
.PHONY : ExperimentalBuild

# fast build rule for target.
ExperimentalBuild/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ExperimentalBuild.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ExperimentalBuild.dir/build
.PHONY : ExperimentalBuild/fast

#=============================================================================
# Target rules for targets named ContinuousUpdate

# Build rule for target.
ContinuousUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousUpdate
.PHONY : ContinuousUpdate

# fast build rule for target.
ContinuousUpdate/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ContinuousUpdate.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ContinuousUpdate.dir/build
.PHONY : ContinuousUpdate/fast

#=============================================================================
# Target rules for targets named ExperimentalStart

# Build rule for target.
ExperimentalStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalStart
.PHONY : ExperimentalStart

# fast build rule for target.
ExperimentalStart/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ExperimentalStart.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ExperimentalStart.dir/build
.PHONY : ExperimentalStart/fast

#=============================================================================
# Target rules for targets named Nightly

# Build rule for target.
Nightly: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Nightly
.PHONY : Nightly

# fast build rule for target.
Nightly/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/Nightly.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/Nightly.dir/build
.PHONY : Nightly/fast

#=============================================================================
# Target rules for targets named ContinuousCoverage

# Build rule for target.
ContinuousCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousCoverage
.PHONY : ContinuousCoverage

# fast build rule for target.
ContinuousCoverage/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage.dir/build
.PHONY : ContinuousCoverage/fast

#=============================================================================
# Target rules for targets named ContinuousStart

# Build rule for target.
ContinuousStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousStart
.PHONY : ContinuousStart

# fast build rule for target.
ContinuousStart/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ContinuousStart.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ContinuousStart.dir/build
.PHONY : ContinuousStart/fast

#=============================================================================
# Target rules for targets named ExperimentalCoverage

# Build rule for target.
ExperimentalCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalCoverage
.PHONY : ExperimentalCoverage

# fast build rule for target.
ExperimentalCoverage/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ExperimentalCoverage.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ExperimentalCoverage.dir/build
.PHONY : ExperimentalCoverage/fast

#=============================================================================
# Target rules for targets named NightlyConfigure

# Build rule for target.
NightlyConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyConfigure
.PHONY : NightlyConfigure

# fast build rule for target.
NightlyConfigure/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/NightlyConfigure.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/NightlyConfigure.dir/build
.PHONY : NightlyConfigure/fast

#=============================================================================
# Target rules for targets named NightlyCoverage

# Build rule for target.
NightlyCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyCoverage
.PHONY : NightlyCoverage

# fast build rule for target.
NightlyCoverage/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/NightlyCoverage.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/NightlyCoverage.dir/build
.PHONY : NightlyCoverage/fast

#=============================================================================
# Target rules for targets named Experimental

# Build rule for target.
Experimental: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Experimental
.PHONY : Experimental

# fast build rule for target.
Experimental/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/Experimental.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/Experimental.dir/build
.PHONY : Experimental/fast

#=============================================================================
# Target rules for targets named spdlog_headers_for_ide

# Build rule for target.
spdlog_headers_for_ide: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 spdlog_headers_for_ide
.PHONY : spdlog_headers_for_ide

# fast build rule for target.
spdlog_headers_for_ide/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/spdlog_headers_for_ide.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/spdlog_headers_for_ide.dir/build
.PHONY : spdlog_headers_for_ide/fast

#=============================================================================
# Target rules for targets named Continuous

# Build rule for target.
Continuous: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Continuous
.PHONY : Continuous

# fast build rule for target.
Continuous/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/Continuous.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/Continuous.dir/build
.PHONY : Continuous/fast

#=============================================================================
# Target rules for targets named ContinuousBuild

# Build rule for target.
ContinuousBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousBuild
.PHONY : ContinuousBuild

# fast build rule for target.
ContinuousBuild/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ContinuousBuild.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ContinuousBuild.dir/build
.PHONY : ContinuousBuild/fast

#=============================================================================
# Target rules for targets named ExperimentalUpdate

# Build rule for target.
ExperimentalUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalUpdate
.PHONY : ExperimentalUpdate

# fast build rule for target.
ExperimentalUpdate/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ExperimentalUpdate.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ExperimentalUpdate.dir/build
.PHONY : ExperimentalUpdate/fast

#=============================================================================
# Target rules for targets named ContinuousTest

# Build rule for target.
ContinuousTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousTest
.PHONY : ContinuousTest

# fast build rule for target.
ContinuousTest/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ContinuousTest.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ContinuousTest.dir/build
.PHONY : ContinuousTest/fast

#=============================================================================
# Target rules for targets named NightlySubmit

# Build rule for target.
NightlySubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlySubmit
.PHONY : NightlySubmit

# fast build rule for target.
NightlySubmit/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/NightlySubmit.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/NightlySubmit.dir/build
.PHONY : NightlySubmit/fast

#=============================================================================
# Target rules for targets named NightlyBuild

# Build rule for target.
NightlyBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyBuild
.PHONY : NightlyBuild

# fast build rule for target.
NightlyBuild/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/NightlyBuild.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/NightlyBuild.dir/build
.PHONY : NightlyBuild/fast

#=============================================================================
# Target rules for targets named NightlyMemoryCheck

# Build rule for target.
NightlyMemoryCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyMemoryCheck
.PHONY : NightlyMemoryCheck

# fast build rule for target.
NightlyMemoryCheck/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/NightlyMemoryCheck.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/NightlyMemoryCheck.dir/build
.PHONY : NightlyMemoryCheck/fast

#=============================================================================
# Target rules for targets named NightlyStart

# Build rule for target.
NightlyStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyStart
.PHONY : NightlyStart

# fast build rule for target.
NightlyStart/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/NightlyStart.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/NightlyStart.dir/build
.PHONY : NightlyStart/fast

#=============================================================================
# Target rules for targets named NightlyUpdate

# Build rule for target.
NightlyUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyUpdate
.PHONY : NightlyUpdate

# fast build rule for target.
NightlyUpdate/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate.dir/build
.PHONY : NightlyUpdate/fast

#=============================================================================
# Target rules for targets named ExperimentalTest

# Build rule for target.
ExperimentalTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalTest
.PHONY : ExperimentalTest

# fast build rule for target.
ExperimentalTest/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ExperimentalTest.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ExperimentalTest.dir/build
.PHONY : ExperimentalTest/fast

#=============================================================================
# Target rules for targets named ExperimentalMemCheck

# Build rule for target.
ExperimentalMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalMemCheck
.PHONY : ExperimentalMemCheck

# fast build rule for target.
ExperimentalMemCheck/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ExperimentalMemCheck.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ExperimentalMemCheck.dir/build
.PHONY : ExperimentalMemCheck/fast

#=============================================================================
# Target rules for targets named NightlyMemCheck

# Build rule for target.
NightlyMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyMemCheck
.PHONY : NightlyMemCheck

# fast build rule for target.
NightlyMemCheck/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/NightlyMemCheck.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/NightlyMemCheck.dir/build
.PHONY : NightlyMemCheck/fast

#=============================================================================
# Target rules for targets named ExperimentalSubmit

# Build rule for target.
ExperimentalSubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalSubmit
.PHONY : ExperimentalSubmit

# fast build rule for target.
ExperimentalSubmit/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ExperimentalSubmit.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ExperimentalSubmit.dir/build
.PHONY : ExperimentalSubmit/fast

#=============================================================================
# Target rules for targets named ContinuousConfigure

# Build rule for target.
ContinuousConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousConfigure
.PHONY : ContinuousConfigure

# fast build rule for target.
ContinuousConfigure/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ContinuousConfigure.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ContinuousConfigure.dir/build
.PHONY : ContinuousConfigure/fast

#=============================================================================
# Target rules for targets named ContinuousMemCheck

# Build rule for target.
ContinuousMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousMemCheck
.PHONY : ContinuousMemCheck

# fast build rule for target.
ContinuousMemCheck/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ContinuousMemCheck.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ContinuousMemCheck.dir/build
.PHONY : ContinuousMemCheck/fast

#=============================================================================
# Target rules for targets named ExperimentalConfigure

# Build rule for target.
ExperimentalConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalConfigure
.PHONY : ExperimentalConfigure

# fast build rule for target.
ExperimentalConfigure/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ExperimentalConfigure.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ExperimentalConfigure.dir/build
.PHONY : ExperimentalConfigure/fast

#=============================================================================
# Target rules for targets named ContinuousSubmit

# Build rule for target.
ContinuousSubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousSubmit
.PHONY : ContinuousSubmit

# fast build rule for target.
ContinuousSubmit/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/ContinuousSubmit.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/ContinuousSubmit.dir/build
.PHONY : ContinuousSubmit/fast

#=============================================================================
# Target rules for targets named NightlyTest

# Build rule for target.
NightlyTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyTest
.PHONY : NightlyTest

# fast build rule for target.
NightlyTest/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/CMakeFiles/NightlyTest.dir/build.make third-party/spdlog-0.13.0/CMakeFiles/NightlyTest.dir/build
.PHONY : NightlyTest/fast

#=============================================================================
# Target rules for targets named catch_tests

# Build rule for target.
catch_tests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 catch_tests
.PHONY : catch_tests

# fast build rule for target.
catch_tests/fast:
	$(MAKE) -f third-party/spdlog-0.13.0/tests/CMakeFiles/catch_tests.dir/build.make third-party/spdlog-0.13.0/tests/CMakeFiles/catch_tests.dir/build
.PHONY : catch_tests/fast

#=============================================================================
# Target rules for targets named backward_object

# Build rule for target.
backward_object: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 backward_object
.PHONY : backward_object

# fast build rule for target.
backward_object/fast:
	$(MAKE) -f third-party/backward-cpp/CMakeFiles/backward_object.dir/build.make third-party/backward-cpp/CMakeFiles/backward_object.dir/build
.PHONY : backward_object/fast

#=============================================================================
# Target rules for targets named backward

# Build rule for target.
backward: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 backward
.PHONY : backward

# fast build rule for target.
backward/fast:
	$(MAKE) -f third-party/backward-cpp/CMakeFiles/backward.dir/build.make third-party/backward-cpp/CMakeFiles/backward.dir/build
.PHONY : backward/fast

#=============================================================================
# Target rules for targets named afina

# Build rule for target.
afina: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 afina
.PHONY : afina

# fast build rule for target.
afina/fast:
	$(MAKE) -f src/CMakeFiles/afina.dir/build.make src/CMakeFiles/afina.dir/build
.PHONY : afina/fast

#=============================================================================
# Target rules for targets named Allocator

# Build rule for target.
Allocator: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Allocator
.PHONY : Allocator

# fast build rule for target.
Allocator/fast:
	$(MAKE) -f src/allocator/CMakeFiles/Allocator.dir/build.make src/allocator/CMakeFiles/Allocator.dir/build
.PHONY : Allocator/fast

#=============================================================================
# Target rules for targets named Concurrency

# Build rule for target.
Concurrency: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Concurrency
.PHONY : Concurrency

# fast build rule for target.
Concurrency/fast:
	$(MAKE) -f src/concurrency/CMakeFiles/Concurrency.dir/build.make src/concurrency/CMakeFiles/Concurrency.dir/build
.PHONY : Concurrency/fast

#=============================================================================
# Target rules for targets named Coroutine

# Build rule for target.
Coroutine: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Coroutine
.PHONY : Coroutine

# fast build rule for target.
Coroutine/fast:
	$(MAKE) -f src/coroutine/CMakeFiles/Coroutine.dir/build.make src/coroutine/CMakeFiles/Coroutine.dir/build
.PHONY : Coroutine/fast

#=============================================================================
# Target rules for targets named Logging

# Build rule for target.
Logging: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Logging
.PHONY : Logging

# fast build rule for target.
Logging/fast:
	$(MAKE) -f src/logging/CMakeFiles/Logging.dir/build.make src/logging/CMakeFiles/Logging.dir/build
.PHONY : Logging/fast

#=============================================================================
# Target rules for targets named Execute

# Build rule for target.
Execute: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Execute
.PHONY : Execute

# fast build rule for target.
Execute/fast:
	$(MAKE) -f src/execute/CMakeFiles/Execute.dir/build.make src/execute/CMakeFiles/Execute.dir/build
.PHONY : Execute/fast

#=============================================================================
# Target rules for targets named Protocol

# Build rule for target.
Protocol: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Protocol
.PHONY : Protocol

# fast build rule for target.
Protocol/fast:
	$(MAKE) -f src/protocol/CMakeFiles/Protocol.dir/build.make src/protocol/CMakeFiles/Protocol.dir/build
.PHONY : Protocol/fast

#=============================================================================
# Target rules for targets named Network

# Build rule for target.
Network: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Network
.PHONY : Network

# fast build rule for target.
Network/fast:
	$(MAKE) -f src/network/CMakeFiles/Network.dir/build.make src/network/CMakeFiles/Network.dir/build
.PHONY : Network/fast

#=============================================================================
# Target rules for targets named Storage

# Build rule for target.
Storage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Storage
.PHONY : Storage

# fast build rule for target.
Storage/fast:
	$(MAKE) -f src/storage/CMakeFiles/Storage.dir/build.make src/storage/CMakeFiles/Storage.dir/build
.PHONY : Storage/fast

#=============================================================================
# Target rules for targets named runCoroutineTests

# Build rule for target.
runCoroutineTests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runCoroutineTests
.PHONY : runCoroutineTests

# fast build rule for target.
runCoroutineTests/fast:
	$(MAKE) -f test/coroutine/CMakeFiles/runCoroutineTests.dir/build.make test/coroutine/CMakeFiles/runCoroutineTests.dir/build
.PHONY : runCoroutineTests/fast

#=============================================================================
# Target rules for targets named runExecuteTests

# Build rule for target.
runExecuteTests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runExecuteTests
.PHONY : runExecuteTests

# fast build rule for target.
runExecuteTests/fast:
	$(MAKE) -f test/execute/CMakeFiles/runExecuteTests.dir/build.make test/execute/CMakeFiles/runExecuteTests.dir/build
.PHONY : runExecuteTests/fast

#=============================================================================
# Target rules for targets named runProtocolTests

# Build rule for target.
runProtocolTests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runProtocolTests
.PHONY : runProtocolTests

# fast build rule for target.
runProtocolTests/fast:
	$(MAKE) -f test/protocol/CMakeFiles/runProtocolTests.dir/build.make test/protocol/CMakeFiles/runProtocolTests.dir/build
.PHONY : runProtocolTests/fast

#=============================================================================
# Target rules for targets named runStorageTests

# Build rule for target.
runStorageTests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runStorageTests
.PHONY : runStorageTests

# fast build rule for target.
runStorageTests/fast:
	$(MAKE) -f test/storage/CMakeFiles/runStorageTests.dir/build.make test/storage/CMakeFiles/runStorageTests.dir/build
.PHONY : runStorageTests/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... edit_cache"
	@echo "... list_install_components"
	@echo "... test"
	@echo "... install/local"
	@echo "... rebuild_cache"
	@echo "... install"
	@echo "... gmock_main"
	@echo "... gmock"
	@echo "... gtest_main"
	@echo "... gtest"
	@echo "... ExperimentalBuild"
	@echo "... ContinuousUpdate"
	@echo "... ExperimentalStart"
	@echo "... Nightly"
	@echo "... ContinuousCoverage"
	@echo "... ContinuousStart"
	@echo "... ExperimentalCoverage"
	@echo "... NightlyConfigure"
	@echo "... NightlyCoverage"
	@echo "... Experimental"
	@echo "... spdlog_headers_for_ide"
	@echo "... Continuous"
	@echo "... ContinuousBuild"
	@echo "... ExperimentalUpdate"
	@echo "... ContinuousTest"
	@echo "... NightlySubmit"
	@echo "... NightlyBuild"
	@echo "... NightlyMemoryCheck"
	@echo "... NightlyStart"
	@echo "... NightlyUpdate"
	@echo "... ExperimentalTest"
	@echo "... ExperimentalMemCheck"
	@echo "... NightlyMemCheck"
	@echo "... ExperimentalSubmit"
	@echo "... ContinuousConfigure"
	@echo "... ContinuousMemCheck"
	@echo "... ExperimentalConfigure"
	@echo "... ContinuousSubmit"
	@echo "... NightlyTest"
	@echo "... catch_tests"
	@echo "... backward_object"
	@echo "... backward"
	@echo "... afina"
	@echo "... Allocator"
	@echo "... Concurrency"
	@echo "... Coroutine"
	@echo "... Logging"
	@echo "... Execute"
	@echo "... Protocol"
	@echo "... Network"
	@echo "... Storage"
	@echo "... runCoroutineTests"
	@echo "... runExecuteTests"
	@echo "... runProtocolTests"
	@echo "... runStorageTests"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

