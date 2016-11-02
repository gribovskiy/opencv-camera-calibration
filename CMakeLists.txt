project(Calibration)
cmake_minimum_required(VERSION 3.2.0)
enable_testing()

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(OpenCV 3 REQUIRED)

# SYSTEM is used to suppress GCC warnings in libraries headers
include_directories(SYSTEM ${OpenCV_INCLUDE_DIR})

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS}")
endif ()

add_subdirectory(opencv-fisheye-calibration)
add_subdirectory(opencv-fisheye-viewer)
add_subdirectory(opencv-standard-calibration)

