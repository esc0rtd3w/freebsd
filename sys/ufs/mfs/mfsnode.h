/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)mfsnode.h	8.3 (Berkeley) 5/19/95
 * $Id: mfsnode.h,v 1.8 1997/02/22 09:47:34 peter Exp $
 */

#ifndef _UFS_MFS_MFSNODE_H_
#define _UFS_MFS_MFSNODE_H_

/*
 * This structure defines the control data for the memory based file system.
 */

struct mfsnode {
	struct	vnode *mfs_vnode;	/* vnode associated with this mfsnode */
	caddr_t	mfs_baseoff;		/* base of file system in memory */
	long	mfs_size;		/* size of memory file system */
	pid_t	mfs_pid;		/* supporting process pid */
	struct buf_queue_head buf_queue;	/* list of I/O requests */
	int	mfs_active;
	long	mfs_spare[1];
};

/*
 * Convert between mfsnode pointers and vnode pointers
 */
#define VTOMFS(vp)	((struct mfsnode *)(vp)->v_data)
#define MFSTOV(mfsp)	((mfsp)->mfs_vnode)

/* Prototypes for MFS operations on vnodes. */
#define mfs_lookup ((int (*) __P((struct  vop_lookup_args *)))mfs_badop)
#define mfs_create ((int (*) __P((struct  vop_create_args *)))mfs_badop)
#define mfs_mknod ((int (*) __P((struct  vop_mknod_args *)))mfs_badop)
#define mfs_access ((int (*) __P((struct  vop_access_args *)))mfs_badop)
#define mfs_getattr ((int (*) __P((struct  vop_getattr_args *)))mfs_badop)
#define mfs_setattr ((int (*) __P((struct  vop_setattr_args *)))mfs_badop)
#define mfs_read ((int (*) __P((struct  vop_read_args *)))mfs_badop)
#define mfs_write ((int (*) __P((struct  vop_write_args *)))mfs_badop)
#define mfs_poll ((int (*) __P((struct  vop_poll_args *)))mfs_badop)
#define mfs_mmap ((int (*) __P((struct  vop_mmap_args *)))mfs_badop)
#define mfs_seek ((int (*) __P((struct  vop_seek_args *)))mfs_badop)
#define mfs_remove ((int (*) __P((struct  vop_remove_args *)))mfs_badop)
#define mfs_link ((int (*) __P((struct  vop_link_args *)))mfs_badop)
#define mfs_rename ((int (*) __P((struct  vop_rename_args *)))mfs_badop)
#define mfs_mkdir ((int (*) __P((struct  vop_mkdir_args *)))mfs_badop)
#define mfs_rmdir ((int (*) __P((struct  vop_rmdir_args *)))mfs_badop)
#define mfs_symlink ((int (*) __P((struct  vop_symlink_args *)))mfs_badop)
#define mfs_readdir ((int (*) __P((struct  vop_readdir_args *)))mfs_badop)
#define mfs_readlink ((int (*) __P((struct  vop_readlink_args *)))mfs_badop)
#define mfs_abortop ((int (*) __P((struct  vop_abortop_args *)))mfs_badop)
#define mfs_lock ((int (*) __P((struct  vop_lock_args *)))vop_nolock)
#define mfs_unlock ((int (*) __P((struct  vop_unlock_args *)))vop_nounlock)
#define mfs_islocked ((int(*) __P((struct vop_islocked_args *)))vop_noislocked)
#define mfs_pathconf ((int (*) __P((struct  vop_pathconf_args *)))mfs_badop)
#define mfs_advlock ((int (*) __P((struct  vop_advlock_args *)))mfs_badop)
#define mfs_blkatoff ((int (*) __P((struct  vop_blkatoff_args *)))mfs_badop)
#define mfs_valloc ((int (*) __P((struct  vop_valloc_args *)))mfs_badop)
#define mfs_vfree ((int (*) __P((struct  vop_vfree_args *)))mfs_badop)
#define mfs_truncate ((int (*) __P((struct  vop_truncate_args *)))mfs_badop)
#define mfs_update ((int (*) __P((struct  vop_update_args *)))mfs_badop)
#define mfs_bwrite ((int (*) __P((struct  vop_bwrite_args *)))vn_bwrite)

#endif
