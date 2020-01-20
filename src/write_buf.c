#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_write_buf(const char* filename, struct fuse_bufvec* buf, off_t off, struct fuse_file_info* fi)
{
    return 0;
}
