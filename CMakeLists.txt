cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(MarineVesselSimulator LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MarineVesselSimulator
    src/main.cpp
    src/geometry.cpp
    src/simulator.cpp
    src/vessel.cpp
)

target_include_directories(MarineVesselSimulator PRIVATE ${CMAKE_SOURCE_DIR}/include)


