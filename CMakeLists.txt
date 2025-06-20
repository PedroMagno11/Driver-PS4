cmake_minimum_required(VERSION 3.29)
project(driver_ps4 C)
set(CMAKE_C_STANDARD 23)

# Inclui headers do projeto e da hidapi
include_directories(include external)

# Onde estão os arquivos .lib ou .dll.a
link_directories(external)

# Biblioteca (API)
add_library(driver_ps4 src/driver_ps4.c)

# Exemplo de uso
add_executable(simple_example_ps4 example/simple_example_ps4.c)

# Link com minha lib e com a hidapi
target_link_libraries(simple_example_ps4 driver_ps4 hidapi)
