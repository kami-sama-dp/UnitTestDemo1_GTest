# cmake最低版本号要求
cmake_minimum_required(VERSION 3.14)

# 项目名
project(Demo)

set(CMAKE_CXX_STANDARD 11)

set(GOOGLETEST_VERSION 1.10.0 )

# 添加头文件, include头文件时搜索的所有目录
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest/include
)

# 添加下级目录，生成.a文件
add_subdirectory( ./googletest)

# 添加连接库
link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest
)

add_executable(${PROJECT_NAME} src/test.cpp include/test.h main.cpp)

# 将目标文件与库文件进行链接
target_link_libraries(${PROJECT_NAME} gtest)

# 指定可执行文件的生成位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")