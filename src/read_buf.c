#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_read_buf(const char* filename, struct fuse_bufvec **bufp, size_t size, off_t off, struct fuse_file_info* fi)
{
    return 0;
}
