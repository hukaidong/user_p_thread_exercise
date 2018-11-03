#include "my_malloc.h"
#include "malloc/global.h"
#include "malloc/segment.h"
#include "utils/utils.h"


void *myallocate(int size, const char *fname,int lnum, char flags) {
  UNUSED(fname);
  UNUSED(lnum);
  if (flags & LIBRARYREQ) {
    seg_p seg = seg_find_avail(sys_vm_base, size);
    seg_insert(seg, size);
    return seg->buf;
  } else if (flags & SHAREDREQ) {
    seg_p seg = seg_find_avail(shared_vm_base, size);
    seg_insert(seg, size);
    return seg->buf;
  } else {
  // get current thread id
  // get current page list
  // if (size + sizeof(seg) > mem per page)
  //     return alloc new page with desired size
  // else foreach page belongs to thread id
  //   if (size < page->free_seg_max)
  //     seg = seg_find_avail(page_base, size)
  //     seg_insert(seg, size)
  //     page->free_seg_max = seg_find_preceeding_max_size(seg);
  // else /* no suitable page */
  //   return alloc page with desired size and set page_max
  }
  return NULL;
}

void mydeallocate(void* pointer, const char *fname, int lnum, char flags) {
  UNUSED(fname);
  UNUSED(lnum);

  if (flags & (LIBRARYREQ | SHAREDREQ)) {
    seg_free(pointer);
  } else {

  // get segheader from pointer
  // segsize = segheader->size
  // if (segsize + sizeof(seg) > mem per page)
  //   split seg into {segpage, seglast}
  //   release (n-1 pages)
  //   thread's pagenum - (n-1)
  // freesize = seg_free(seglast)
  // if (freesize > segheaders->maxavail)
  //   segheader->maxavail = freesize
  //   if (freesize + sizeof(seg) = mem per page)
  //   release (last page)
  //   thread's pagenum - 1
  }

}
