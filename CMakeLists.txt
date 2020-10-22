cmake_minimum_required(VERSION 3.0)
project(md5compare)

add_executable(md5compare
    "src/main.c"
    "src/md5.c"
    "src/md5.h"
)