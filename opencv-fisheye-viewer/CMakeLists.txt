set(srcs
   main.cpp
)

add_executable(opencv-fisheye-viewer ${srcs})
target_link_libraries(opencv-fisheye-viewer ${OpenCV_LIBS})
