cmake_minimum_required(VERSION 3.10)
project(integral_executor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS -lboost_program_options)
#set(CMAKE_CXX_FLAGS_RELEASE -O3)

set(EXECUTABLE_NAME integrates)
set(EXECUTABLE_OUTPUT_PATH ./bin)
set(INCLUDE_DIR ./include)
set(SRC_DIR ./src)

set(FUNCS_SRC_DIR ${SRC_DIR}/functions)
set(METHODS_SRC_DIR ${SRC_DIR}/methods)

find_package(Boost 1.67 COMPONENTS program_options REQUIRED)

file(GLOB SRCS
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/integral.cpp
        ${FUNCS_SRC_DIR}/*.cpp
        ${METHODS_SRC_DIR}/*.cpp
        )

include_directories(${INCLUDE_DIR})
include_directories(${INCLUDE_DIR}/functions)
include_directories(${INCLUDE_DIR}/methods)

add_executable(${EXECUTABLE_NAME} ${SRCS})
