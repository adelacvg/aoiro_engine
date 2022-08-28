cmake_minimum_required(VERSION 3.10)
project(Aoiro_core)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)
message("CMAKE BUILD TYPE IS: ${CMAKE_BUILD_TYPE}")
# set(CMAKE_GENERATOR "MINGW Makefiles")
# set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystems/vcpkg.cmake")
# set(CMAKE_CXX_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-release-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe")
# set(CMAKE_C_COMPLIER "C:/Program Files/mingw-w64/x86_64-8.1.0-release-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe")


find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glad CONFIG REQUIRED)

file(GLOB_RECURSE SRC_FILES
        "${PROJECT_SOURCE_DIR}/src/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        "${PROJECT_SOURCE_DIR}/src/*.cc"
        "${PROJECT_SOURCE_DIR}/src/*.cpp")

# message("SRC FILES ARE: ${SRC_FILES}")
# add_executable(Aoiro_core main.cpp)
# set(SOURCE_FILES main.cpp)
message("FILES ARE: ${SRC_FILES}")
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_sources(${CMAKE_PROJECT_NAME} PUBLIC ${SRC_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE GLEW::GLEW)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glad::glad)

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_20)


add_custom_command(
  TARGET ${CMAKE_PROJECT_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/src/shaders/basic.vert"
  "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/src/shaders/basic.vert"
)
add_custom_command(
  TARGET ${CMAKE_PROJECT_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/src/shaders/basic.frag"
  "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/src/shaders/basic.frag"
)
# add_custom_command(
#   TARGET ${CMAKE_PROJECT_NAME}
#   POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy_directory
#   "${PROJECT_SOURCE_DIR}/src/shaders"
#   "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/src/shaders"
# )