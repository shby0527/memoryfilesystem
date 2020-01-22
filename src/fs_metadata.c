#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "fs.h"
#include "fs_metada.h"

struct memfs_tree_metadata* create_metadata(const char* name)
{
    struct memfs_tree_metadata* rtn = (struct memfs_tree_metadata*) malloc(sizeof(struct memfs_tree_metadata));
    memset(rtn, 0, sizeof(struct memfs_tree_metadata));
    size_t len = strlen(name);
    rtn->count = 0;
    rtn->name = (char*)malloc(sizeof(char) * (len + 1));
    memcpy(rtn->name, name, len);
    return rtn;
}