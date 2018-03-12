# Project definitions
cmake_minimum_required (VERSION 3.0)
project (midogen)
set (CMAKE_CXX_STANDARD 11)

# Vendor libraries
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS system program_options filesystem)

# Header files location
include_directories("src")
include_directories(${Boost_INCLUDE_DIRS})

# Main library: all classes implementations
file(GLOB CLASSES src/*.cpp)
list(REMOVE_ITEM CLASSES src/midogen.cpp)
add_library(MidogenLib ${CLASSES})

# Testing program
option(UNIT_TESTS "build unit tests" OFF)
if(UNIT_TESTS)
    file(GLOB TEST_FILES test/*.cpp)
    enable_testing()
    add_library(Catch INTERFACE)
    target_include_directories(Catch INTERFACE "${PROJECT_SOURCE_DIR}/test")
    add_executable(midogen_test ${TEST_FILES})
    target_link_libraries(midogen_test Catch MidogenLib)
    add_test(AllMidogenTests midogen_test)
endif()

# Main program
add_executable(midogen "src/midogen.cpp")
target_link_libraries(midogen MidogenLib 
    Boost::system Boost::program_options Boost::filesystem)
