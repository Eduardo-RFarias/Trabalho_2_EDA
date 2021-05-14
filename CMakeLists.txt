cmake_minimum_required(VERSION 3.0.0)
project(trabalho2 VERSION 0.1.0)

add_library(lib
lib/Abp.cpp
lib/Menu.cpp
)

add_executable(trabalho2 main.cpp)

target_link_libraries(trabalho2 lib)
