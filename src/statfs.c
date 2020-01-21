#include "config.h"
#include "operator.h"
#include "options.h"
#include <fuse.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#define FILE_INODE_COUNT 2199023254528
#define FILE_NAME_MAX 81920

int mfs_statfs(const char* path, struct statvfs* fst)
{
    UNUSED(path);
    struct fuse_context* content = fuse_get_context();
    struct memfs_options* opts = (struct memfs_options*) content->private_data;
    memset(fst, 0, sizeof(struct statvfs));
    fst->f_bsize = opts->block_size;
    fst->f_bfree = opts->max_size;
    fst->f_frsize = 0;
    fst->f_blocks = opts->max_size;
    fst->f_bavail = opts->max_size;
    fst->f_files =  FILE_INODE_COUNT;
    fst->f_ffree =  FILE_INODE_COUNT;
    fst->f_favail = FILE_INODE_COUNT;
    fst->f_namemax = FILE_NAME_MAX;
    return 0;
}
