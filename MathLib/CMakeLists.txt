cmake_minimum_required(VERSION 3.10)
project(MathLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加源文件
set(SOURCES
    math_lib.cpp
)

# 创建静态库
add_library(math_lib_static STATIC ${SOURCES})
set_target_properties(math_lib_static PROPERTIES
    OUTPUT_NAME "math_lib"
    POSITION_INDEPENDENT_CODE ON
)

# 创建动态库
add_library(math_lib_shared SHARED ${SOURCES})
set_target_properties(math_lib_shared PROPERTIES
    OUTPUT_NAME "math_lib"
    POSITION_INDEPENDENT_CODE ON
)

# 在Windows上定义导出宏
if(WIN32)
    target_compile_definitions(math_lib_shared PRIVATE MATH_LIB_EXPORTS)
endif()

# 创建使用静态库的可执行文件
add_executable(static_example main.cpp)
target_link_libraries(static_example math_lib_static)

# 创建使用动态库的可执行文件
add_executable(shared_example main.cpp)
target_link_libraries(shared_example math_lib_shared)

# 安装规则
install(TARGETS math_lib_static math_lib_shared static_example shared_example
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
install(FILES math_lib.h DESTINATION include) 