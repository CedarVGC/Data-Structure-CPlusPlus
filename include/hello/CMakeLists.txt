
 # 并将名称保存到 DIR_LIB_SRCS 变量
 aux_source_directory(. DIR_LIB_SRCS)
 # 生成链接库
 add_library (hello ${DIR_LIB_SRCS} hello_son.h)