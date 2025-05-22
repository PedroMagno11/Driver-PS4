cmake_minimum_required(VERSION 3.29)
project(driver_ps4 C)
set(CMAKE_C_STANDARD 23)

include_directories(include external)
link_directories(external)


add_library(driver_ps4 src/driver_ps4.c)

add_executable(simple_example_ps4 example/simple_example_ps4.c)
target_link_libraries(simple_example_ps4 driver_ps4 hidapi)