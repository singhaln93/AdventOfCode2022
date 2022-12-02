# Copyright © 2022  Neeraj Singhal
# All rights reserved

cmake_minimum_required(VERSION 3.24)
# CMAKE_VERSION <major>.<minor>.<date>(YYMMDD) or <patch>
project(
  AoC
  VERSION 0.0.221202
  LANGUAGES CXX)
message("-- PROJECT = ${CMAKE_PROJECT_NAME} v${CMAKE_PROJECT_VERSION}")

# Set Options/FLAGS
option(NAT_PCKG "Display packages which are natively used for the project." OFF)
option(DEP_PCKG "Display packages dependent packages used for the project." OFF)

if(NAT_PCKG)
  include(scripts/cmake/nativePckg.cmake)
endif()

if(DEP_PCKG)
  include(scripts/cmake/depPckg.cmake)
endif()

if(NOT TARGET spdlog)
  find_package(spdlog REQUIRED)
endif()

# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) conan_basic_setup()

# Set the compiler options
set(CMAKE_CXX_STANDARD 20) # > Cxx standard to 11/14/17/20
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES main.cpp)

# create main executable file
add_executable(${PROJECT_NAME} ${SOURCES} lib/util.h)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog) #${CONAN_LIBS})
