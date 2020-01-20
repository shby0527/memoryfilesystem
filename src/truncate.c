#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_truncate(const char* filename, off_t offset, struct fuse_file_info* fi)
{
    return 0;
}
