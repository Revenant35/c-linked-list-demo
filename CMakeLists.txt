cmake_minimum_required(VERSION 3.31)
project(c_linked_list_demo C)

set(CMAKE_C_STANDARD 23)

add_executable(c_linked_list_demo main.c
        linked-list.h)
