cmake_minimum_required(VERSION 3.26)
project(Yandex)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Werror -Wextra -O0")

add_executable(Yandex
        src/E-Closeness.cc)
