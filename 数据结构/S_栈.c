/*************************************************************************
	> File Name: S_栈.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月26日 星期四 19时55分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct Stack
{
    int top;
    int size;
    ElementType data[0];
}Stack;

Stack * create(int size)//创建栈，为栈分配空间
{
    Stack * stack = (Stack*)malloc(sizeof(Stack) + size * sizeof(ElementType));
    if(stack == NULL)
    {
        printf("error:栈空间分配失败！\n");
        return NULL;//失败返回NULL
    }
    else
    {
        stack->top = -1;
        stack->size = size;
        printf("初始化成功\n");
        return stack;//成功返回栈头地址
    }

}
void pop(Stack * stack)//出栈
{
    if(stack->top == -1)
    {
        printf("栈为空\n");
    }
    else
    {
        printf("%d\n",stack->data[stack->top]);
        --(stack->top);
    }
}

int push(Stack * stack, ElementType a)//入栈
{
    if(stack->top == stack->size - 1)
    {
        printf("栈满\n");
        return -1;//失败返回-1
    }
    else
    {
        stack->top++;
        stack->data[stack->top] = a;
        printf("入栈成功\n");
        return 0;//成功返回0
    }

}

int is_empty(Stack * stack)//判断是否为空,栈空返回-1;栈不空返回0
{
    if(stack->top == -1)
    {
        printf("栈为空\n");
        return -1;
    }
    else
    {
        printf("栈不空\n");
        return 0;
    }

}

int is_full(Stack *stack)//判断是否满,栈满返回-1,栈空返回0
{
    if(stack->top == stack->size - 1)
    {
        printf("栈满\n");
        return -1;
    }
    else
    {
        printf("栈未满\n");
        return 0;
    }
}

int clear_stack(Stack * stack)//清空栈，失败返回-1,成功返回0
{
    if(stack == NULL)
    {
        return -1;
    }
    else
    {
        stack->top = -1;
        return 0;
    }
}

void destory_stack(Stack ** s)//摧毁栈，释放栈内存
{
    if(*s != NULL)
    {
        free(*s);
        *s = NULL;
    }
}

int main()
{
    Stack * a;
    a = create(10);//创建大小为10的栈
    if(is_full(a) == 0)//栈不满则可放入
    {
        push(a, 1);//入栈
        push(a, 20);
    }
    if(is_empty(a) == 0)//栈不空则可出栈
    {
        pop(a);//出栈
        pop(a);
    }

    return 0;
}
