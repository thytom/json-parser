cmake_minimum_required(VERSION 3.16)

project(jsonparser CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES "src/*.cpp")

add_library(jsonparser ${SOURCES})

target_include_directories(jsonparser PUBLIC include/)
