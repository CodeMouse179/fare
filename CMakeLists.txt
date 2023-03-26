cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)

project(CodeMouse_fare)

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows" OR ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_executable(f
        fare/main.cpp
        fare/olcPixelGameEngine.h
        fare/olcPGEX_TTF.h
        fare/String.hpp
        fare/System.hpp
    )
endif()

if(APPLE)
    add_executable(f
        fare/main.cpp
        fare/olcPGEMac.h
        fare/olcPGEX_TTF.h
        fare/String.hpp
        fare/System.hpp
    )
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

    find_library(FREETYPE_LIBRARY freetype)
    target_link_libraries(f ${FREETYPE_LIBRARY})
endif()

if(APPLE)
    find_library(CARBON_LIBRARY Carbon)
    target_link_libraries(f ${CARBON_LIBRARY})

    find_package(PNG REQUIRED)
    include_directories(${PNG_INCLUDE_DIRS})
    link_directories(${PNG_LIBRARY_DIRS})
    add_definitions(${PNG_DEFINITIONS})
    if(NOT PNG_FOUND)
        message(ERROR " PNG not found!")
    endif(NOT PNG_FOUND)
    target_link_libraries(f ${PNG_LIBRARIES})

    find_package(GLUT REQUIRED)
    include_directories(${GLUT_INCLUDE_DIRS})
    link_directories(${GLUT_LIBRARY_DIRS})
    add_definitions(${GLUT_DEFINITIONS})
    if(NOT GLUT_FOUND)
        message(ERROR " GLUT not found!")
    endif(NOT GLUT_FOUND)
    target_link_libraries(f ${GLUT_LIBRARIES})

    find_package(OpenGL REQUIRED)
    include_directories(${OpenGL_INCLUDE_DIRS})
    link_directories(${OpenGL_LIBRARY_DIRS})
    add_definitions(${OpenGL_DEFINITIONS})
    if(NOT OPENGL_FOUND)
        message(ERROR " OPENGL not found!")
    endif(NOT OPENGL_FOUND)
    target_link_libraries(f ${OPENGL_LIBRARIES})

endif()