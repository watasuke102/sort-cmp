# CMAKE_EXPORT_COMPILE_COMMANDS required 3.5
cmake_minimum_required(VERSION 3.5)

project(
  sort-cmp
  LANGUAGES C
)

get_filename_component(srcdir "${CMAKE_SOURCE_DIR}" REALPATH)
get_filename_component(bindir "${CMAKE_BINARY_DIR}" REALPATH)
if ("${srcdir}" STREQUAL "${bindir}")
  message(FATAL_ERROR "Please use 'build' dir; Try '-Bbuild' option")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic -Werror -g")

include_directories("./inc")

add_executable(${PROJECT_NAME}
  "main.c"
)

target_link_libraries(${PROJECT_NAME})
