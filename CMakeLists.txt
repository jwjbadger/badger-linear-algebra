cmake_minimum_required(VERSION 3.24)

# project data
project(
	"BadLinAlg" 
	VERSION 0.1
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_subdirectory(include/BadLinAlg)

# testing
set(BUILD_TESTING ON)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
   AND BUILD_TESTING)
	enable_testing()

    add_subdirectory(tests)
endif()
