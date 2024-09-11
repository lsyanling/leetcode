# CMake 的最低版本要求
cmake_minimum_required(VERSION 3.30)

# 显式设置编译器
set(CMAKE_C_COMPILER "C:/Program Files/llvm-mingw-20240619-ucrt-x86_64/bin/clang.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files/llvm-mingw-20240619-ucrt-x86_64/bin/clang++.exe")
set(CMAKE_RC_COMPILER "C:/Program Files/llvm-mingw-20240619-ucrt-x86_64/bin/windres.exe")

# 设置项目名称和使用的语言
project(main LANGUAGES C CXX)

# 添加可执行文件
add_executable(main main.cpp)

# 为目标设置编译选项，启用 C++ 草案版本 (C++2c)
target_compile_options(${PROJECT_NAME} PRIVATE -std=c++2c)
