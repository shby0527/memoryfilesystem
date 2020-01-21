#include "config.h"
#include "operator.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <fuse.h>
#include <fuse_lowlevel.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int mfs_getattr(const char* filename, struct stat* state, struct fuse_file_info* fi)
{
    memset(state, 0, sizeof(struct stat));
    state->st_mode = S_IFDIR  | 0755;
    state->st_nlink = 1;
    state->st_size = 4096;
    state->st_uid = getuid();
    state->st_gid = getgid();
    state->st_atime = state->st_mtime = state->st_ctime = time(NULL);
    return 0;
}