#include "config.h"
#include "operator.h"
#include <fuse.h>

ssize_t mfs_copy_file_range(const char* path_in, struct fuse_file_info* fi_in, 
                            off_t offset_in, const char* path_out, struct fuse_file_info* fi_out, 
                            off_t offset_out, size_t size, int flags)
{
    return 0;
}
