cmake_minimum_required(VERSION 3.26)
project(TextRPGGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(TextRPGGame main.cpp
        Character.cpp
        Character.h
        Game.cpp
        Game.h)
