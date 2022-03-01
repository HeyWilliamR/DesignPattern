#递归查找当前所有文件
file(GLOB_RECURSE DIR_BEHAVIRORAL_SRCS *.c *.h)
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_FACTORY_SRCS 变量
#aux_source_directory(./* DIR_FACTORY_SRCS)
message("======")
message(${DIR_BEHAVIRORAL_SRCS})
# 生成链接库
add_library (BEHAVIORAL_PATTERN ${DIR_BEHAVIRORAL_SRCS})