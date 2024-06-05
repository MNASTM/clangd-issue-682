cmake_minimum_required(VERSION 3.20)

set(CMAKE_SYSTEM_PROCESSOR x86-64)
set(CMAKE_C_COMPILER_ID Clang)
set(CMAKE_CXX_COMPILER_ID Clang)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project(app1-sw1)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(TARGET_FLAGS "${EXT_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TARGET_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TARGET_FLAGS}")

set(source_files
"pack-div@1.1.0/src/div.c"
"./src/main.c"
)

include_directories(
  "pack-div@1.1.0/inc"
  "./inc"
)

add_executable(app1-sw1 ${source_files})