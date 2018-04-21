#include"max_heap.h"

bool max_heap_construct_bybuffer(max_heap *heap, max_heap_type buff[], int length)
{
	if (NULL != heap->idatas)
	{
		return false;
	}
	heap->iheap_capacity = length;
	heap->iheap_size = 0;
	heap->idatas = (max_heap_type*)malloc(sizeof(max_heap_type) * length);
	for (int i = 0; i < length; ++i)
	{
		max_heap_push(heap, buff[i]);
	}
	return true;
}

bool max_heap_desturct(max_heap *heap)
{
	if (NULL == heap->idatas)
	{
		return false;
	}
	free(heap->idatas);
	return true;

}

int  max_heap_getsize(max_heap *heap)
{
	return heap->iheap_size;
}

bool max_heap_isfull(max_heap *heap)
{
	if (heap->iheap_capacity == heap->iheap_size)
	{
		return true;
	}
	return false;
}

bool max_heap_isempty(max_heap *heap)
{
	if (0 == heap->iheap_size)
	{
		return true;
	}
	return false;
}

void max_heap_swap(max_heap_type *a, max_heap_type *b)
{
	max_heap_type t = *a;
	*a = *b;
	*b = t;
}

void max_heap_float(max_heap *heap, int index)
{
	for (int i = index; i > 0; i = i / 2)
	{
		if (i == 1)
		{
			if (heap->idatas[1] > heap->idatas[0])
			{
				max_heap_swap(&heap->idatas[1], &heap->idatas[0]);
			}
		}
		else if (heap->idatas[i - 1] > heap->idatas[i / 2 - 1])
		{
			max_heap_swap(&heap->idatas[i - 1], &heap->idatas[i /2 - 1]);
		}
		else
		{
			break;
		}
	}
}
void max_heap_sink(max_heap *heap, int index)
{
	int i = index;

	while (i * 2 <= heap->iheap_size)
	{
		if (heap->idatas[i - 1] < heap->idatas[i * 2 - 1])//it compare to left child
		{
			max_heap_swap(&heap->idatas[i - 1], &heap->idatas[i * 2 - 1]);
			if (i * 2 + 1 <= heap->iheap_size && heap->idatas[i - 1] < heap->idatas[i * 2])
				//it compare to right child
			{
				max_heap_swap(&heap->idatas[i - 1], &heap->idatas[i * 2]);
			}
			i = i * 2;
		}
		else if (i * 2 + 1 <= heap->iheap_size && heap->idatas[i - 1] < heap->idatas[i * 2])
			//is compare to right child
		{
			max_heap_swap(&heap->idatas[i - 1], &heap->idatas[i * 2]);
			i = i * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

bool max_heap_push(max_heap *heap, max_heap_type data)
{
	if (max_heap_isfull(heap))
	{
		return false;
	}
	heap->idatas[heap->iheap_size] = data;
	++heap->iheap_size;
	max_heap_float(heap, heap->iheap_size);
}
bool max_heap_pop(max_heap *heap, int index)
{
	if (max_heap_isempty(heap))
	{
		return false;
	}
	heap->idatas[index - 1] = heap->idatas[heap->iheap_size - 1];
	--heap->iheap_size;
	max_heap_sink(heap, index);
}

void max_heap_printall(max_heap *heap)
{
	if (max_heap_isempty(heap))
	{
		printf("heap is empty!\n");
	}
	printf("heap:\t");
	int i = 0;
	while (i < heap->iheap_size)
	{
		printf("%d\t", heap->idatas[i]);
		++i;
	}
	putchar(10);
}


