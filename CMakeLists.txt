# How to use this file:
# Set URHO3D_HOME to be the place where you built Urho3D. It should contain
# bin/, include/, and lib/
# Then, run the following in the command line:

# cmake CMakeLists.txt -DLIBDIR_URHO3D=<URHO3D_SOURCE>

# <URHO3D_SOURCE> is where you extracted Urho3D. It should have a bunch of
# cmake scripts. I suggest you setup a script for these procedures.
cmake_minimum_required(VERSION 3.2.3)

project(THKame)

set(LIBDIR_URHO3D "~/Urho3D"
    CACHE STRING "Path to Urho3D source" )

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# All headers are placed beside the sources
include_directories("${PROJECT_SOURCE_DIR}")

# Include Urho3D
include_directories("$ENV{URHO3D_HOME}/include")
include_directories("$ENV{URHO3D_HOME}/include/Urho3D/ThirdParty") # Must be included
set(CMAKE_MODULE_PATH ${LIBDIR_URHO3D}/CMake/Modules)
include(Urho3D-CMake-common)
find_package(Urho3D REQUIRED)

# Enable C++ 11
add_compile_options(-std=c++11)

SET(SOURCE_FILES
	thk.cpp)

set(TARGET_NAME THKame)

# These are Urho3D specific functions 
define_source_files()
setup_main_executable()
