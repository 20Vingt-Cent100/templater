cmake_minimum_required(VERSION 4.4)
project(templater)

set(CMAKE_CXX_STANDARD 20)

add_executable(templater main.cpp
        headers/argsParser.h
        source/argsParser.cpp
        source/templateDefinition.cpp
        headers/templateDefinition.h
        headers/platform.h
        source/yamlParser.cpp
        headers/yamlParser.h
        source/fileUtils.cpp
        headers/fileUtils.h
        tests/argumentParsingTests.cpp)
