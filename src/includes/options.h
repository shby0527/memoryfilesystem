#ifndef OPTIONS_H
#define OPTIONS_H
#include <stddef.h>
#include "fs.h"

/**
 * 文件系统自定义参数
 * */
struct memfs_options {
    // 最大大小
    size_t max_size;

    // 块大小
    size_t block_size;

    // 是否帮助
    short show_help;

    /////////////////////////////////////
    // 被使用的块
    size_t used_blocks;

    // 被使用的inode
    size_t used_inode;

    // root 目录
    struct memfs_tree_metadata* root;
};

#define OPTION(t, n, p)                           \
    { t, offsetof(struct n, p), 1 }


#define UNUSED(p) ((void)p)

#endif