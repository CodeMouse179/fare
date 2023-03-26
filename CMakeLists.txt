cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)

project(CodeMouse_fare)

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows" OR ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_executable(f
        fare/main.cpp
        fare/olcPixelGameEngine.h
        fare/String.hpp
        fare/System.hpp
    )
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "macOS")

endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    find_library(X11_LIBRARY X11)
    target_link_libraries(f ${X11_LIBRARY})

    find_library(GL_LIBRARY GL)
    target_link_libraries(f ${GL_LIBRARY})

    find_library(PTHREAD_LIBRARY pthread)
    target_link_libraries(f ${PTHREAD_LIBRARY})

    find_library(PNG_LIBRARY png)
    target_link_libraries(f ${PNG_LIBRARY})
endif()