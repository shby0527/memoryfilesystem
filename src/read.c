#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_read(const char* filename, char* buffer, size_t len, off_t offset, struct fuse_file_info* fi)
{
    return 0;
}
