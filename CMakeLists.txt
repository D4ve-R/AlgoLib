cmake_minimum_required(VERSION 3.2)

project(AlgoLib VERSION 0.1
                DESCRIPTION "A header only library for sorting algos"
                HOMEPAGE_URL "https://github.com/D4ve-R/AlgoLib"
                )

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory("lib")

target_include_directories(${PROJECT_NAME} PUBLIC "${${PROJECT_NAME}_SOURCE_DIR}/lib")

add_executable(example example.cpp)
