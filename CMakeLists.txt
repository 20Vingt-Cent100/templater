cmake_minimum_required(VERSION 4.4)
project(templater)

set(CMAKE_CXX_STANDARD 20)

add_executable(templater main.cpp
        source/argsParser.h
        source/argsParser.cpp
        source/templateDefinition.cpp
        source/templateDefinition.h)
