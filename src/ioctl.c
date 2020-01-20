#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_ioctl(const char* filename, unsigned int cmd, void* arg, struct fuse_file_info* fi, unsigned int flags, void* data)
{
    return 0;
}
