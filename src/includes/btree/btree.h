#ifndef BTREE_H
#define BTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>

#include "fs.h"

// 文件系统目录结构数据结构
struct memfs_tree_metadata
{
    // 当前目录下的文件名
    char* name;

    // 他的子节点
    struct memfs_tree_metadata* children;

    // 子节点的数量
    size_t count;

    // 所对应的文件系统文件元数据
    struct memfs_metadata* file;
};

#endif