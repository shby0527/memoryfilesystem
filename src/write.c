#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_write(const char* filename, const char* data, size_t len, off_t offset, struct fuse_file_info* fi)
{
    return 0;
}
