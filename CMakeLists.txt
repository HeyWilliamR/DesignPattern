# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.4)

# 项目信息
project (DesignPattern)

# 查找当前目录下的所有源文件
# 并将名称保存到 DESIGN_PATTERN 变量
aux_source_directory(. DESIGN_PATTERN)

# 添加 creational_pattern 子目录
add_subdirectory(./creational_pattern/)

# 添加 behavioral_pattern 子目录
add_subdirectory(./behavioral_pattern/)

# 添加 behavioral_pattern 子目录
add_subdirectory(./structural_pattern/)

# 指定生成目标
aux_source_directory(. DIR_SRCS)
add_executable(DESIGN_PATTERN ${DIR_SRCS})

# 添加链接库
target_link_libraries(DESIGN_PATTERN CREATIONAL_PATTERN BEHAVIORAL_PATTERN STRUCTURAL_PATTERN)