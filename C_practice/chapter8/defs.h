/*
 * Defintions for a simple memory
 * allocator from K&R, will use
 * the first-fit menality
 * which will look for the smallest
 * block that will satisy the request
 *
 */

#ifndef __DEFS_H__
#define __DEFS_H__



#define <stddef.h>


struct block {
    size_t size;
    struct block *next;
    size_t space;
};



#endif
