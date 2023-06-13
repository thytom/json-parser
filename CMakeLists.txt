cmake_minimum_required(VERSION 3.16)

project(json-parser CXX)

file(GLOB SOURCES "src/*.cpp")

add_subdirectory(app)
add_subdirectory(jsonparser)
