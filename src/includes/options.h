#ifndef OPTIONS_H
#define OPTIONS_H
#include <stddef.h>

/**
 * 文件系统自定义参数
 * */
struct memfs_options {
    // 最大大小
    size_t max_size;

    // 是否帮助
    short show_help;
};

#define OPTION(t, n, p)                           \
    { t, offsetof(struct n, p), 1 }


#define UNUSED(p) ((void)p)

#endif