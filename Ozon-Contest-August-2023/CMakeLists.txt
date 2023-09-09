cmake_minimum_required(VERSION 3.25.2)
project(OzonContest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Werror -Wextra")

add_executable(OzonContest
        real/e.cc)
