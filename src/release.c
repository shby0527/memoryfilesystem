#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_release(const char* filename, struct fuse_file_info* fi)
{
    return 0;
}
