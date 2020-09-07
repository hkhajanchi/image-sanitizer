cmake_minimum_required(VERSION 3.0.0)
project (image_sanitizer)

# Compiler settings 
SET (CMAKE_CXX_COMPILER "g++")
SET (CMAKE_CXX_FLAGS "-O3 -std=c++17 -pthread")

#paths and shit - this is specific to the CV build in my docker container
SET (OPENCV_INCLUDE_DIRS "/usr/local/include/opencv4" )
SET (OPENCV_LIBS "/usr/local/lib")

# Add source files 
SET (src "/hack/src/main.cpp")

# OpenCV include headers
include_directories( ${OPENCV_INCLUDE_DIRS})

# build executable
add_executable (sanitize ${src})

# add necessary OpenCV dynamic libs and add to executable
find_library (core      NAMES opencv_core      ${OPENCV_LIBS})
find_library (imgproc   NAMES opencv_imgproc   ${OPENCV_LIBS})
find_library (imgcodecs NAMES opencv_imgcodecs ${OPENCV_LIBS})

target_link_libraries (sanitize ${core} ${imgproc} ${imgcodecs})
