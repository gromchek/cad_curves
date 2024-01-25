cmake_minimum_required(VERSION 3.10)

project(cad)

add_executable(cad main.cpp)
add_compile_definitions(_USE_MATH_DEFINES)
add_subdirectory(curves)


if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)

    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)
    target_link_libraries(cad PRIVATE Threads::Threads)
endif()

set_target_properties(cad PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

target_link_libraries(cad PUBLIC curves)
