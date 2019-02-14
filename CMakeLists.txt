cmake_minimum_required(VERSION 3.13)
project(OFCT_MMR)

set(CMAKE_CXX_STANDARD 17)

add_executable(OFCT_MMR main.cpp Player.h)

set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")