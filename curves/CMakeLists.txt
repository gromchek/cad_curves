cmake_minimum_required (VERSION 3.10)

project (curves)
add_library(curves SHARED Circle.cpp Ellipse.cpp Helix.cpp)
target_include_directories(curves PUBLIC .)
set_target_properties(curves PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_custom_command(TARGET curves POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_BINARY_DIR}/Debug/curves.dll" "${CMAKE_BINARY_DIR}/Debug/curves.dll") 
endif()

if(WIN32 AND NOT MSVC)
    add_custom_command(TARGET curves POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_BINARY_DIR}/libcurves.dll" "${CMAKE_BINARY_DIR}/") 
endif()
