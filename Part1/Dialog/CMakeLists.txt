cmake_minimum_required(VERSION 3.20)
project(Test_vector)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_executable(Test_vector main.cpp Dialog.cpp Dialog.h)

include(FindPkgConfig)
find_package(Vector REQUIRED)
include_directories(${VECTOR_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${VECTOR_LIBRARY})