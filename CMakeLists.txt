project(THKame)
# How to use this file:
# 1. Make an environment variable: (You don't have to do this if your
#    installation is native.
# LD_LIBRARY_PATH = <sfml-install-path>/lib
# 2. Execute the following in the command line
# cmake CMakeLists.txt
#		-DSFML_INCLUDE_DIR:STRING=<sfml-header-path>
#		-DSFML_LIBRARY_DIR:STRING=<sfml-library-path>

cmake_minimum_required(VERSION 3.5)
# SFML_INCLUDE_DIR should have a subdir named SFML
set(SFML_INCLUDE_DIR "/usr/include"
  CACHE STRING "Path to SFML headers" )
set(SFML_LIBRARY_DIR "/usr/lib/x86_64-linux-gnu"
  CACHE STRING "Path to SFML library" )

set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Do not remove the following auto-generated signatures

# Auto-generated. Do not edit. All changes will be undone
set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/core/thklog.cpp
    ${PROJECT_SOURCE_DIR}/core/thkame.cpp
    ${PROJECT_SOURCE_DIR}/client/thkameclient.cpp
   )
# Auto-generated end

# All headers are placed beside the sources
include_directories("${SFML_INCLUDE_DIR}")
link_directories(${SFML_LIBRARY_DIR})

# Include SFML
# Enable C++ 11
add_compile_options(-std=c++11)

add_executable(THKame ${SOURCE_FILES})
set(TARGET_NAME THKame)
target_link_libraries(THKame sfml-graphics sfml-window sfml-system)
