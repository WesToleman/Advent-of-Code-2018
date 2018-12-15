cmake_minimum_required(VERSION 3.3.0)
Project(AdventOfCode2018
	DESCRIPTION "Solutions to the 2018 Advent of Code problems"
	LANGUAGES CXX)

include(CTest)

add_library(AOCLib INTERFACE)
target_include_directories(AOCLib INTERFACE lib)

add_executable(ChronalCalibration
	day_01_chronal_calibration/chronal_calibration.cpp)
target_compile_features(ChronalCalibration PUBLIC cxx_std_17)
target_link_libraries(ChronalCalibration AOCLib)
target_include_directories(ChronalCalibration PUBLIC day_01_chronal_calibration)

# Unit Testing
find_package(Catch2 REQUIRED)

add_library(TestRunner STATIC test/test_runner.cpp)
target_link_libraries(TestRunner Catch2::Catch2)

add_executable(AOCLibTests test/aoc_lib_tests.cpp)
target_link_libraries(AOCLibTests AOCLib TestRunner)

add_executable(ChronalCalibrationTests day_01_chronal_calibration/chronal_calibration_tests.cpp)
target_link_libraries(ChronalCalibrationTests TestRunner)

add_executable(InventoryManagementSystemTests day_02_inventory_management_system/inventory_management_system_tests.cpp)
target_link_libraries(InventoryManagementSystemTests TestRunner)

enable_testing()
add_test(NAME AOCLibTests COMMAND AOCLibTests)
add_test(NAME ChronalCalibrationTests COMMAND ChronalCalibrationTests)
add_test(NAME InventoryManagementSystemTests COMMAND InventoryManagementSystemTests)
