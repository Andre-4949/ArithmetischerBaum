cmake_minimum_required(VERSION 3.28)
project(LaborRechenBaum)

set(CMAKE_CXX_STANDARD 26)

file(GLOB_RECURSE SRC "./include/*.h" "./include/*.hpp" "./src/*.cpp")

add_executable(LaborRechenBaum ${SRC})
