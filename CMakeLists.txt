cmake_minimum_required(VERSION 3.0.0)
project(trabalho2 VERSION 0.1.0)

add_library(lib
lib/Abp.cpp
lib/Menu.cpp
lib/Transcritor.cpp
)

set (
    CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out"
)

add_executable(trabalho2 main.cpp)

target_link_libraries(trabalho2 lib)
