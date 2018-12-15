cmake_minimum_required(VERSION 3.3.0)
Project(AdventOfCode2018
	DESCRIPTION "Solutions to the 2018 Advent of Code problems"
	LANGUAGES CXX)

include(CTest)

# Unit Testing
find_package(Catch2 REQUIRED)

add_library(TestRunner STATIC test/test_runner.cpp)
target_link_libraries(TestRunner Catch2::Catch2)

enable_testing()
