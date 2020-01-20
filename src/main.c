#include "config.h"
#include "operator.h"
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <assert.h>

#include "options.h"

#define DEFAULT_SIZE 4294967296

/**
 * 初始化操作函数
 * */
static struct fuse_operations operators = {
    .getattr = mfs_getattr,
    .readlink = mfs_readlink,
    .mknod = mfs_mknod,
    .mkdir = mfs_mkdir,
    .unlink = mfs_unlink,
    .rmdir = mfs_rmdir,
    .symlink = mfs_symlink,
    .rename = mfs_rename,
    .link = mfs_link,
    .chmod = mfs_chmod,
    .chown = mfs_chown,
    .truncate = mfs_truncate,
    .open = mfs_open,
    .read = mfs_read,
    .write = mfs_write,
    .statfs = mfs_statfs,
    .flush = mfs_flush,
    .release = mfs_release,
    .fsync = mfs_fsync,
    .setxattr = mfs_setxattr,
    .getxattr = mfs_getxattr,
    .listxattr = mfs_listxattr,
    .removexattr = mfs_removexattr,
    .opendir = mfs_opendir,
    .readdir = mfs_readdir,
    .releasedir = mfs_releasedir,
    .fsyncdir = mfs_fsyncdir,
    .init = memoryfs_init,
    .destroy = memoryfs_destroy,
    .access = mfs_access,
    .lock = mfs_lock,
    .utimens = mfs_utimens,
    .bmap = mfs_bmap,
    .ioctl = mfs_ioctl,
    .poll = mfs_poll,
    .write_buf = mfs_write_buf,
    .read_buf = mfs_read_buf,
    .flock = mfs_flock,
    .fallocate = mfs_fallocate,
    .copy_file_range = mfs_copy_file_range,
    .lseek = mfs_lseek,
};

static struct memfs_options sys_options = { 0 };

static const struct fuse_opt options[] = {
	OPTION("--max-count=%d", memfs_options, max_size),
    OPTION("-mc %d", memfs_options, max_size),
	OPTION("--help", memfs_options , show_help),
	OPTION("-h", memfs_options , show_help),
	FUSE_OPT_END
};

void * memoryfs_init(struct fuse_conn_info *conn, struct fuse_config *cfg)
{
	UNUSED(conn);

	// 设置禁止缓存文件
	cfg->auto_cache = 0;
	cfg->kernel_cache = 0;
	
	return &sys_options;
}

void memoryfs_destroy(void* private_data)
{
    UNUSED(private_data);
	printf("file system will be exit");
}

static void show_help(const char *progname)
{
	printf("usage: %s [options] <mountpoint>\n\n", progname);
	printf("File-system specific options:\n"
	       "    -mc --max-count=<num>   Size of the memory fs max storage (byte)"
	       "        (default: 4G)\n"
	       "\n");
}

int main(int argc, char** args) 
{
    printf("memory filesystem %s \n\n\n", MEMFS_VERSION);
	int ret = 0;
	struct fuse_args fargs = FUSE_ARGS_INIT(argc, args);
	sys_options.max_size = DEFAULT_SIZE;

	if (fuse_opt_parse(&fargs, &sys_options, options, NULL) == -1) {
		return -1;
	}

	if (sys_options.show_help) {
		show_help(args[0]);
		assert(fuse_opt_add_arg(&fargs, "--help") == 0);
		fargs.argv[0][0] = '\0';
	}

	ret = fuse_main(fargs.argc, fargs.argv, &operators, &sys_options);

	fuse_opt_free_args(&fargs);

    return ret;
}