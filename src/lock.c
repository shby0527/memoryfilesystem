#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_lock(const char* filename, struct fuse_file_info* fi, int cmd, struct flock* lock)
{
    return 0;
}
