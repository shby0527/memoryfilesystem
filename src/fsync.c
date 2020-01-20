#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_fsync(const char* filename, int datasync, struct fuse_file_info* fi)
{
    return 0;
}
