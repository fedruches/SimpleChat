cmake_minimum_required(VERSION 3.15)

project(SimpleChat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads)

if (WIN32)

message(STATUS "message: WIN32")

set(Boost_USE_STATIC_LIBS ON)
set(BOOST_ROOT "c:\\boost")
set(Boost_INCLUDE_DIRS "c:\\boost\\include")
set(Boost_LIBRARIES "c:\\boost\\lib")

find_package(Boost 1.75.0 COMPONENTS system REQUIRED)

if (Boost_FOUND)
    message(STATUS "message: Boost_FOUND")

    include_directories(${Boost_INCLUDE_DIRS})
endif()

elseif(UNIX)
    message(STATUS "message: UNIX")

    find_package(Boost 1.71 REQUIRED COMPONENTS system)
    include_directories(${Boost_INCLUDE_DIR})
endif()

add_executable(${PROJECT_NAME} main.cpp message.cpp)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} Threads::Threads)