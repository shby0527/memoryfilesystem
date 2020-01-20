#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_readdir(const char* filename, void* data,fuse_fill_dir_t buf_fill, off_t offset, struct fuse_file_info* fi, enum fuse_readdir_flags flags)
{
    return 0;
}
