/************************************************************************/
/* ��ģ���ڴ�������                                                   */
/************************************************************************/
#pragma once
#ifndef _MOON_MALLOC_H
#define _MOON_MALLOC_H

#ifdef __cplusplus
extern "C" {
#endif

extern void* moon_malloc(unsigned int num_bytes);/*allocate memory*/

extern void moon_free(void* memory);/*free point*/

#ifdef __cplusplus
}
#endif

#endif