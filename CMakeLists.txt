project(THKame)
# How to use this file:
# 1. Create the environment variables: (You don't have to do this if your
#    installation is native.)
# LD_LIBRARY_PATH = <sfml-install-path>/lib
# BOOST_ROOT = <libboost>
# BOOST_LIBRARYDIR = <libboost-libraries>
# 2. Execute the following in the command line
# cmake CMakeLists.txt

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    message("debug mode")
endif(CMAKE_BUILD_TYPE MATCHES DEBUG)
cmake_minimum_required(VERSION 3.5)

set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# All headers are placed beside the sources
include_directories("${SFML_INCLUDE_DIR}")
link_directories(${SFML_LIBRARY_DIR})

# Include Boost
find_package(Boost 1.61.0 COMPONENTS thread REQUIRED)
if (${Boost_FOUND})
	include_directories(${Boost_INCLUDE_DIRS})
	link_directories(${Boost_LIBRARY_DIR})
endif()

find_package(Threads REQUIRED)

add_compile_options(-std=c++14)

# Do not remove the following auto-generated signatures

# Auto-generated. Do not edit. All changes will be undone
set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/core/Scene.cpp
    ${PROJECT_SOURCE_DIR}/core/Resources.cpp
   )
# Auto-generated end

add_executable(THKame ${SOURCE_FILES})
set(TARGET_NAME THKame)
target_link_libraries(THKame ${Boost_LIBRARIES})
target_link_libraries(THKame sfml-graphics sfml-window sfml-system)
target_link_libraries(THKame m)
target_link_libraries(THKame ${CMAKE_THREAD_LIBS_INIT})
