cmake_minimum_required(VERSION 3.26)

project(Win32ClientAreaCapture)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} gdi32 user32 kernel32)
