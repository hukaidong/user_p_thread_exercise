#define LIBRARYREQ 0x01
#define THREADREQ 0x02
#define SHAREDREQ 0x04

#define malloc(x) myallocate(x, __FILE__, __LINE__, THREADREQ)
#define free(x) mydeallocate(x, __FILE__, __LINE__, THREADREQ)
#define shalloc(x) myallocate(x, __FILE__, __LINE__, SHAREDREQ)

#define _lib_malloc(x) myallocate(x, __FILE__, __LINE__, LIBRARYREQ)
#define _lib_free(x) mydeallocate(x, __FILE__, __LINE__, LIBRARYREQ)

void *myallocate(int size, const char *fname,int lnum, char flags);
void mydeallocate(void *pointer, const char *fname, int line, char flags);