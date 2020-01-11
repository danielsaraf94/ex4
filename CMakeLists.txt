cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
include_directories(.)

add_executable(ex4
        CacheManager.h
        ClientHandler.h
        FileCacheManager.cpp
        FileCacheManager.h
        main.cpp
        MySerialServer.cpp
        MySerialServer.h
        MyTestClientHandler.cpp
        MyTestClientHandler.h
        Problem.h
        ServerSide.h
        Solution.h
        Solver.h)
