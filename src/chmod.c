#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_chmod(const char* filename, mode_t mode, struct fuse_file_info* fi)
{
    return 0;
}