cmake_minimum_required(VERSION 3.8)

project(SimpleChat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.71 REQUIRED COMPONENTS system filesystem)
find_package(Threads)

include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} Boost::filesystem Threads::Threads)