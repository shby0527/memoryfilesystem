#ifndef MEMFS_METADATA_H
#define MEMFS_METADATA_H
/**
 * 文件系统操作函数 
 * */
#include "fs.h"
#include "linktable/linktable.h"

struct memfs_tree_metadata* create_metadata(const char*);

#endif