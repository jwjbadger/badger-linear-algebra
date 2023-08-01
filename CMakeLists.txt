cmake_minimum_required(VERSION 3.24)

# project data
project(
	"BadLinAlg" 
	VERSION 0.1
    LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(TOPLEVEL_PROJECT TRUE)
else()
  set(TOPLEVEL_PROJECT FALSE)
endif()


set(INSTALL_BAD_LIBRARY "install library in default location" CACHE INTERNAL ${TOPLEVEL_PROJECT})
option(BUILD_BAD_TESTING "build tests" ${TOPLEVEL_PROJECT})
option(BUILD_BAD_DOC "gen docfiles (unused currently)" ${TOPLEVEL_PROJECT})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_subdirectory(include/BadLinAlg)

# testing
set(BUILD_TESTING ON)

if((TOPLEVEL_PROJECT OR MODERN_CMAKE_BUILD_TESTING)
   AND BUILD_TESTING)
	enable_testing()

    add_subdirectory(tests)
endif()
