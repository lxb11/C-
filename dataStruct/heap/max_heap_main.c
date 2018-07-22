#include"max_heap.h"
#include<stdio.h>
#include<windows.h>
int main()
{
	int buffer[10] = { 0,1,2,3,4,5,6,7,8,9 };//index 1-10
	max_heap heap = { 0 };
	max_heap_construct_bybuffer(&heap, buffer, 10);
	max_heap_printall(&heap);
	max_heap_pop(&heap, 1);
	max_heap_printall(&heap);
	max_heap_pop(&heap, 1);
	max_heap_printall(&heap);
	max_heap_pop(&heap, 1);
	max_heap_printall(&heap);
	system("pause");
	return 0;
}