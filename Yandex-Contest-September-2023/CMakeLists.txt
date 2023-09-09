cmake_minimum_required(VERSION 3.26)
project(Yandex)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++20 -O0")

add_executable(Yandex
        src/E-Closeness.cc)
