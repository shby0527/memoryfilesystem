#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_fallocate(const char* filename, int mode, off_t offset, off_t len, struct fuse_file_info* fi)
{
    return 0;
}
