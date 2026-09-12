cmake_minimum_required(VERSION 3.16)
project(csv2md LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(csv2md src/main.cpp)

install(TARGETS csv2md RUNTIME DESTINATION bin)
