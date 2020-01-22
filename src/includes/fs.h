#ifndef MEMFS_FS_H
#define MEMFS_FS_H
// 文件系统元数据
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "linktable/linktable.h"

// 文件系统元数据
struct memfs_metadata
{
    // 用户属组
    uid_t uid;
    gid_t gid;
    // 文件名
    char* filename;
    // 文件权限和模式
    mode_t mode;
    // 文件大小
    size_t size;
    // 文件占有的块
    size_t blocks;
    // 文件的引用次数
    size_t refs;
    // 文件内容
    struct memfs_data_block* content;
};

#endif