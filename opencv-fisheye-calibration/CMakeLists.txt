set(srcs
   main.cpp
)

add_executable(opencv-fisheye ${srcs})
target_link_libraries(opencv-fisheye ${OpenCV_LIBS})
