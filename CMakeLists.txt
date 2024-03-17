cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
include_directories()
add_executable(untitled inc/main.cpp
        inc/spaceships.cpp
        inc/spaceships.h
        inc/events.h
        inc/commonship.cpp
        inc/strongship.cpp
        inc/speedship.cpp
        inc/shipfleetmanager.h
        inc/strongship2.h
        inc/commonship2.h
        inc/speedship2.h
        inc/eventss.cpp
)
