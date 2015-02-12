/* 
 * File:   Util.h
 * Author: alex
 *
 * Created on 12. Februar 2015, 20:12
 */

#ifndef UTIL_H
#define	UTIL_H

template<typename t>
t *copyToHeap(t *obj)
{
  t* ptr = malloc(sizeof(*obj));
  memcpy(ptr, obj, sizeof(*obj));
  return ptr;
}

#endif	/* UTIL_H */

