#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_getattr(const char* filename, struct stat* state, struct fuse_file_info* fi)
{
    return 0;
}