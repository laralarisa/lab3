cmake_minimum_required(VERSION 2.8)
project( lab3 )
find_package( OpenCV REQUIRED )
add_executable( lab3 lab3.cpp )
target_link_libraries( lab3 ${OpenCV_LIBS} )

