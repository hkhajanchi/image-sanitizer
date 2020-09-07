project (image_sanitizer)

# Compiler settings 
SET (CMAKE_CXX_COMPILER "clang++-10")
SET (CMAKE_CXX_FLAGS "-O3 -g")

#paths and shit - this is specific to the CV build in my docker container
SET (OPENCV_INCLUDE_DIRS "/usr/local/include/opencv4" )
SET (OPENCV_LIBS "/usr/local/lib")

SET (src "/hack/src")
SET (target "foo")

# Source dependencies
# find_package(OpenCV REQUIRED)

include_directories( ${OPENCV_INCLUDE_DIRS})
add_executable (${target} ${src}})
target_link_libraries (${target} ${OpenCV_LIBS})
