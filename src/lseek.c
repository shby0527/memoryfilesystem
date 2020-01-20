#include "config.h"
#include "operator.h"
#include <fuse.h>

off_t mfs_lseek(const char* filename, off_t off, int whence, struct fuse_file_info* fi)
{
    return 0;
}
