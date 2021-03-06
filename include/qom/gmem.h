/* GLIB - Library of useful routines for C programming
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/. 
 */

#ifndef __G_MEM_H__
#define __G_MEM_H__

#include "qom/gtypes.h"

G_BEGIN_DECLS


/* Memory allocation functions
 */
gpointer g_malloc         (gulong	 n_bytes);
gpointer g_malloc0        (gulong	 n_bytes);
gpointer g_realloc        (gpointer	 mem, gulong n_bytes);
void	 g_free	          (gpointer	 mem);


/* Convenience memory allocators
 */
#define g_new(struct_type, n_structs)		\
    ((struct_type *) g_malloc (((gsize) sizeof (struct_type)) * ((gsize) (n_structs))))
#define g_new0(struct_type, n_structs)		\
    ((struct_type *) g_malloc0 (((gsize) sizeof (struct_type)) * ((gsize) (n_structs))))
#define g_renew(struct_type, mem, n_structs)	\
    ((struct_type *) g_realloc ((mem), ((gsize) sizeof (struct_type)) * ((gsize) (n_structs))))

G_END_DECLS

#endif /* __G_MEM_H__ */

