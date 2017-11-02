cmake_minimum_required(VERSION 2.8.4)
project(FuckMouse)    

    
    set(header_path "./include")
    set(SFML_HEADER_PATH "/usr/local/lib/SFML-2.4.2/include")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    set(SFML_LIB_PATH "/usr/local/lib/SFML-2.4.2/build/lib")

    include_directories(${header_path} ${SFML_HEADER_PATH})
    
    find_library(fuck_mouse_lib 
                NAMES libmouse.dylib
                PATHS ./lib)


    set(SOURCE_FILE
        main.cpp
        ${header_path}/xinputsimulator.h
        ${SFML_HEADER_PATH}/SFML/Window.hpp)

    add_executable(FuckMouse ${SOURCE_FILE})
    
    target_link_libraries(FuckMouse 
                        ${fuck_mouse_lib} 
                        ${SFML_LIB_PATH}/libsfml-window.2.4.2.dylib
                        ${SFML_LIB_PATH}/libsfml-system.2.4.2.dylib)
                        
