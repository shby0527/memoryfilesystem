#ifndef OPERATOR_H
#define OPERATOR_H
#include "config.h"
#include <fuse.h>

int mfs_getattr(const char *, struct stat *, struct fuse_file_info *fi);
 
int mfs_readlink(const char *, char *, size_t);
 
int mfs_mknod(const char *, mode_t, dev_t);
 
int mfs_mkdir(const char *, mode_t);
 
int mfs_unlink(const char *);
 
int mfs_rmdir(const char *);
 
int mfs_symlink(const char *, const char *);
 
int mfs_rename(const char *, const char *, unsigned int flags);
 
int mfs_link(const char *, const char *);
 
int mfs_chmod(const char *, mode_t, struct fuse_file_info *fi);
 
int mfs_chown(const char *, uid_t, gid_t, struct fuse_file_info *fi);
 
int mfs_truncate(const char *, off_t, struct fuse_file_info *fi);
 
int mfs_open(const char *, struct fuse_file_info *);
 
int mfs_read(const char *, char *, size_t, off_t, struct fuse_file_info *);
 
int mfs_write(const char *, const char *, size_t, off_t, struct fuse_file_info *);
 
int mfs_statfs(const char *, struct statvfs *);
 
int mfs_flush(const char *, struct fuse_file_info *);
 
int mfs_release(const char *, struct fuse_file_info *);
 
int mfs_fsync(const char *, int, struct fuse_file_info *);
 
int mfs_setxattr(const char *, const char *, const char *, size_t, int);
 
int mfs_getxattr(const char *, const char *, char *, size_t);
 
int mfs_listxattr(const char *, char *, size_t);
 
int mfs_removexattr(const char *, const char *);
 
int mfs_opendir(const char *, struct fuse_file_info *);
 
int mfs_readdir(const char *, void *, fuse_fill_dir_t, off_t, struct fuse_file_info *, enum fuse_readdir_flags);
 
int mfs_releasedir(const char *, struct fuse_file_info *);
 
int mfs_fsyncdir(const char *, int, struct fuse_file_info *);
 
void* memoryfs_init(struct fuse_conn_info *conn, struct fuse_config *cfg);
 
void memoryfs_destroy(void *private_data);
 
int mfs_access(const char *, int);
  
int mfs_lock(const char *, struct fuse_file_info *, int cmd, struct flock *);
 
int mfs_utimens(const char *, const struct timespec tv[2], struct fuse_file_info *fi);
 
int mfs_bmap(const char *, size_t blocksize, uint64_t *idx);
 
int mfs_ioctl(const char *, unsigned int cmd, void *arg, struct fuse_file_info *, unsigned int flags, void *data);
 
int mfs_poll(const char *, struct fuse_file_info *, struct fuse_pollhandle *ph, unsigned *reventsp);
 
int mfs_write_buf(const char *, struct fuse_bufvec *buf, off_t off, struct fuse_file_info *);
 
int mfs_read_buf(const char *, struct fuse_bufvec **bufp, size_t size, off_t off, struct fuse_file_info *);
 
int mfs_flock(const char *, struct fuse_file_info *, int op);
 
int mfs_fallocate(const char *, int, off_t, off_t, struct fuse_file_info *);
 
ssize_t mfs_copy_file_range(const char *path_in, struct fuse_file_info *fi_in, off_t offset_in, const char *path_out, struct fuse_file_info *fi_out, off_t offset_out, size_t size, int flags);
 
off_t mfs_lseek(const char *, off_t off, int whence, struct fuse_file_info *);
#endif