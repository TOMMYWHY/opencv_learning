cmake_minimum_required(VERSION 3.14)
project(opencv_01)

# 添加OpenCV库
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

#set(SOURCE_FILES main.cpp)
#add_executable(Video ${SOURCE_FILES})
#target_link_libraries(Video ${OpenCV_LIBS}) # 链接库

add_executable(opencv_01 main.cpp)
target_link_libraries(opencv_01 ${OpenCV_LIBS}) # 链接库

#add_executable(opencv_01 main.cpp)


