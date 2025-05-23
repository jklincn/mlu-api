cmake_minimum_required(VERSION 3.22)
project(${SKBUILD_PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -fPIC -std=c++17 -pthread -O3")

# --- neuware ---
set(NEUWARE_HOME "/usr/local/neuware")
include_directories(${NEUWARE_HOME}/include)
link_directories(${NEUWARE_HOME}/lib)
link_directories(${NEUWARE_HOME}/lib64)

# --- pybind11 ---
set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

# --- cndev module ---
pybind11_add_module(_cndev MODULE csrc/cndev.cpp)
target_link_libraries(_cndev PRIVATE cndev)
set_target_properties(_cndev PROPERTIES OUTPUT_NAME "cndev")
install(TARGETS _cndev DESTINATION ${SKBUILD_PROJECT_NAME})