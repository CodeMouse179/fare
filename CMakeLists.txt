cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)

project(fare)

add_executable(f
    fare/olcPixelGameEngine.h
    fare/String.hpp
    fare/main.cpp
)

find_library(X11_LIBRARY X11)
target_link_libraries(f ${X11_LIBRARY})

find_library(GL_LIBRARY GL)
target_link_libraries(f ${GL_LIBRARY})

find_library(PTHREAD_LIBRARY pthread)
target_link_libraries(f ${PTHREAD_LIBRARY})

find_library(PNG_LIBRARY png)
target_link_libraries(f ${PNG_LIBRARY})
