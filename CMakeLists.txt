# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.4)

# 项目信息
project (DesignPattern)

# 查找当前目录下的所有源文件
# 并将名称保存到 DESIGN_PATTERN 变量
aux_source_directory(. DESIGN_PATTERN)

# 添加 FACTORY_PATTERN 子目录
add_subdirectory(Factory)

# 指定生成目标
add_executable(DESIGN_PATTERN main.cc)

# 添加链接库
target_link_libraries(DESIGN_PATTERN FactoryFunctions)