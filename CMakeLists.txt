cmake_minimum_required(VERSION 3.2.3)

project(THKame)

set(LIBDIR_URHO3D "/usr/share/lib/Urho3D"
    CACHE STRING "Path to Urho3D source (The folder containing a bunch of cmake scripts" )

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}")

# Include Urho3D
include_directories("$ENV{URHO3D_HOME}/include")
set(CMAKE_MODULE_PATH ${LIBDIR_URHO3D}/CMake/Modules)
include(Urho3D-CMake-common)
find_package(Urho3D REQUIRED)

# Enable C++ 11
add_compile_options(-std=c++11)

SET(SOURCE_FILES
	thk.cpp)

set(TARGET_NAME THKame)
define_source_files()
setup_main_executable()
