file(GLOB SOURCES "src/*.cpp")

add_executable(main
    ${SOURCES})

target_include_directories(main PUBLIC include/)

target_link_libraries(main PUBLIC jsonparser)
