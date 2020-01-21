#include "config.h"
#include "operator.h"
#include <fuse.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int mfs_open(const char* filename, struct fuse_file_info* fi)
{
    if (strcmp("hello.txt", filename + 1) !=0) {
        return -ENOENT;
    }
    fi->fh = 10;
    return 0;
}
