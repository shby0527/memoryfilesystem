#include "config.h"
#include "operator.h"
#include "options.h"
#include <fuse.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "fs.h"

int mfs_readdir(const char* filename, void* data,fuse_fill_dir_t buf_fill, off_t offset, struct fuse_file_info* fi, enum fuse_readdir_flags flags)
{
    struct fuse_context* context = fuse_get_context();
    struct memfs_options* options = (struct memfs_options*)context->private_data;
    struct memfs_tree_metadata* root = options->root;
    
    if (root == NULL) {
        return -EIO;
    }
    struct memfs_tree_metadata* current;
    if (strcmp(root->name, filename) == 0) {
        current = root;
    } else {
        // 搜索
        return -ENOENT;
    }
    if (current == NULL) {
        return -EIO;
    }
    buf_fill(data, ".", NULL, 0, 0);
    buf_fill(data, "..", NULL, 0, 0);
    if (current->children != NULL) {
        struct memfs_tree_metadata* child = root->children;
        while(child != NULL) {
            struct memfs_metadata* file = child->file;
            if (file == NULL) {
                // 无效错误文件
                continue;
            }
            struct stat* state = (struct stat*) malloc(sizeof(struct stat));
            state->st_atime = file->modify;
            state->st_ctime = file->create;
            state->st_mtime = file->modify;
            state->st_uid = file->uid;
            state->st_gid = file->gid;
            state->st_mode = file->mode;
            state->st_size = file->size;
            state->st_nlink = file->refs;
            buf_fill(data, file->filename, state, 0, 0);
        }
    }
    return 0;
}
