#include "config.h"
#include "operator.h"
#include <fuse.h>
#include <linux/fs.h>

int mfs_rename(const char* source, const char* target, unsigned int flags)
{
    if ( flags == RENAME_NOREPLACE) {
        return -1;
    }
    return 0;
}