set(srcs
   main.cpp
)

add_executable(opencv-standard ${srcs})
target_link_libraries(opencv-standard ${OpenCV_LIBS})
