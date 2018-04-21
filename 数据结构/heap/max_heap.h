#ifndef __MAXHEAP_H
#define __MAXHEAP_H

#include"my_bool.h"
#include<stdlib.h>
#include<stdio.h>

typedef int max_heap_type;
typedef struct
{
	int iheap_capacity;
	int iheap_size;
	max_heap_type *idatas;
}max_heap;//ÈáÐÔÊý×é

bool max_heap_construct_bybuffer(max_heap *heap, max_heap_type buff[], int length);
bool max_heap_desturct(max_heap *heap);
int max_heap_getsize(max_heap *heap);
bool max_heap_isfull(max_heap *heap);
bool max_heap_isempty(max_heap *heap);
void max_heap_swap(max_heap_type *a, max_heap_type *b);
void max_heap_float(max_heap *heap, int index);
void max_heap_sink(max_heap *heap, int index);
bool max_heap_push(max_heap *heap, max_heap_type data);
bool max_heap_pop(max_heap *heap, int index);
void max_heap_printall(max_heap *heap);


#endif
