cmake_minimum_required(VERSION 3.14)
set(PROJECT_NAME "serwer")
project(${PROJECT_NAME})

set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/libs/SFML-2.5.1/lib/cmake/SFML")
#set(TGUI_DIR "${CMAKE_CURRENT_LIST_DIR}/libs/TGUI-0.8/lib/cmake/TGUI")

#file(GLOB ALL_REQUIRED_DLL "libs/required_dlls/*.dll")
#file(COPY ${ALL_REQUIRED_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#file(GLOB TGUI_DLL "libs/TGUI-0.8/bin/*.dll")
#file(COPY ${TGUI_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_CXX_STANDARD 17)
link_libraries(stdc++fs) #link the filesystem



set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} )
target_link_libraries(${CMAKE_PROJECT_NAME} ws2_32)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
#find_package(TGUI 0.8 REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system sfml-network)