cmake_minimum_required(VERSION 3.7)
project(Wolf3d)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -lmlx -framework OpenGL -framework AppKit")

set(SOURCE_FILES
        src/main.c
        src/create_image.c


src/create_win.c
src/putPixel.c
src/createMap.c
src/findRay.c
src/putColumn.c
src/rayCasting.c
        src/buttons.c src/rotate.c)

add_executable(Wolf3d ${SOURCE_FILES})