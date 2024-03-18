cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
include_directories()
add_executable(untitled src/main.cpp
        src/spaceships.cpp
        inc/spaceships.h
        inc/events.h
        src/commonship.cpp
        src/strongship.cpp
        src/speedship.cpp
        inc/shipfleetmanager.h
        inc/strongship2.h
        inc/commonship2.h
        inc/speedship2.h
        src/eventss.cpp
)
