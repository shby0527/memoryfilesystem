#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fuse.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>


int main(int argc, char** args) {
    printf("memory filesystem %s \n", MEMFS_VERSION);

    return 0;
}