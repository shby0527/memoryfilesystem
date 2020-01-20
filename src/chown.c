#include "config.h"
#include "operator.h"
#include <fuse.h>

int mfs_chown(const char* filename, uid_t uid, gid_t gid, struct fuse_file_info* fi)
{
    return 0;
}