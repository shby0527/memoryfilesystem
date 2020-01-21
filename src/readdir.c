#include "config.h"
#include "operator.h"
#include <fuse.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int mfs_readdir(const char* filename, void* data,fuse_fill_dir_t buf_fill, off_t offset, struct fuse_file_info* fi, enum fuse_readdir_flags flags)
{
    if (strcmp(filename, "/") == 0) {
        buf_fill(data, ".", NULL, 0, 0);
        buf_fill(data, "..", NULL, 0, 0);
        return 0;
    } else {
        return -ENOENT;
    }
    return 0;
}
