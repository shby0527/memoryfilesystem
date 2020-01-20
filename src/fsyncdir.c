#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_fsyncdir(const char* filename, int syncdata, struct fuse_file_info* fi)
{
    return 0;
}
