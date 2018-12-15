cmake_minimum_required(VERSION 3.3.0)
Project(AdventOfCode2018
	DESCRIPTION "Solutions to the 2018 Advent of Code problems"
	LANGUAGES CXX)

include(CTest)

add_library(AOCLib INTERFACE)
target_include_directories(AOCLib INTERFACE lib)

# Unit Testing
find_package(Catch2 REQUIRED)

add_library(TestRunner STATIC test/test_runner.cpp)
target_link_libraries(TestRunner Catch2::Catch2)

add_executable(AOCLibTests test/aoc_lib_tests.cpp)
target_link_libraries(AOCLibTests AOCLib TestRunner)

enable_testing()
add_test(NAME AOCLibTests COMMAND AOCLibTests)
