#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_utimens(const char* filename, const struct timespec tv[2], struct fuse_file_info* fi)
{
    return 0;
}
