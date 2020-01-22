#ifndef LINKTABLE_H
#define LINKTABLE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// 文件系统数据块大小链表结构
struct memfs_data_block {
    // 本块数据的大小
    size_t len;
    // 本块数据的可用大小
    size_t free;
    // 本块数据(一次性分配够数据块大小)
    char* data;
    // 下一个连续块
    struct memfs_data_block* next;
    // 上一个连续块
    struct memfs_data_block* prev;
};

#endif