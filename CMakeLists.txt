cmake_minimum_required(VERSION 3.7)
project(Wolf3d)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -framework OpenGL -framework Appkit ")

set(SOURCE_FILES
        main.c
        libmlx.a
        wolf3d.h)

add_executable(Wolf3d ${SOURCE_FILES})