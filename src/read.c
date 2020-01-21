#include "config.h"
#include "operator.h"
#include <fuse.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int mfs_read(const char* filename, char* buffer, size_t len, off_t offset, struct fuse_file_info* fi)
{
    if (strcmp("hello.txt", filename + 1) !=0) {
        return -ENOENT;
    }
    char* c = "hello world \n\0";
    memcpy(buffer, c, strlen(c));
    return strlen(c);
}
