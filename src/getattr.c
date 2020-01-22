#include "config.h"
#include "options.h"
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

#include "fs.h"

int mfs_getattr(const char* filename, struct stat* state, struct fuse_file_info* fi)
{
    struct fuse_context* context = fuse_get_context();
    struct memfs_options* options = (struct memfs_options*)context->private_data;
    struct memfs_tree_metadata* root = options->root;
    
    if (root == NULL) {
        return -EIO;
    }
    struct memfs_metadata* file;
    if (strcmp(root->name, filename) == 0) {
        file = root->file;
    } else {
        // 就搜索
        return -ENOENT;
    }
    if (file == NULL) {
        return -EIO;
    }
    memset(state, 0, sizeof(struct stat));
    state->st_atime = file->modify;
    state->st_ctime = file->create;
    state->st_mtime = file->modify;
    state->st_uid = file->uid;
    state->st_gid = file->gid;
    state->st_mode = file->mode;
    state->st_size = file->size;
    state->st_nlink = file->refs;
    return 0;
}