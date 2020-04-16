cmake_minimum_required(VERSION 3.15)
project(LottiKarotti)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.hpp") #glob all the source files intp one place
include_directories("src/")

add_executable(LottiKarotti ${SOURCES} main.cpp)