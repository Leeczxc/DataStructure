cmake_minimum_required(VERSION 3.23)
project(DataStructure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(ListNode)
include_directories(StackAndQueue)

add_executable(DataStructure main.cpp StackAndQueue/maxSliding239.h)
