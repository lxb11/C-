/*************************************************************************
	> File Name: Q_队列.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 10时56分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int element_type;
typedef struct Queue
{
    int capacity;
    int front;  //允去删除的一端称为队头
    int rear;   //允许插入的一端称为队尾
    int array[0];
}Queue;

Queue * create(int size)//创建队列，为队列分配空间
{
    Queue * q = (Queue*)malloc(sizeof(Queue) + size * sizeof(element_type));
    if(q == NULL)
    {
        printf("error:队列空间分配失败！\n");
        return NULL;
    }
    else
    {
       q->capacity = size + 1;  //循环队列损失一个数据
       q->front = -1; 
       q->rear = -1; //初始化参数
       printf("创建成功！\n");
       return q;
    }
}

int is_empty(Queue * q)//队列为空返回-1;否则返回0
{
    if(q->front == q->rear)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}

int is_full(Queue *q)//队列满返回-1,否则返回0
{
    if(q->front == (q->rear + 1) % q->capacity)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int in_queue(Queue *q, element_type val)//入队
{
    if(-1 == is_full(q))
    {
        printf("队列已满,入队失败\n");
        return -1;//队满，入队失败
    }
    else
    {
        q->rear = (q->rear + 1) % q->capacity;
        q->array[q->rear] = val;
        printf("入栈成功\n");
        return 0;
    }
}

element_type out_queue(Queue *q)//出队
{
    if(-1 == is_empty(q))
    {
        printf("队列为空，出队失败\n");
        return -1;//队空，出队失败
    }
    else
    {
        q->front = (q->front + 1) % q->capacity;//对头加1
        return q->array[q->front];//对头元素出队返回
    }
}

void travel_queue(Queue *q) //遍历队列所有元素并打印
{
    int tmp = q->front;
    while(tmp != q->rear)
    {
        tmp++;
        printf("%d\n",q->array[tmp]);
    }
}

int main()
{
    Queue * q;
    q = create(5);
    is_empty(q);
    in_queue(q, 1);
    in_queue(q, 2);
    in_queue(q, 3);
    if(-1 == is_empty(q))
    {
        printf("队列为空\n");
    }
    else
    {
        printf("队列不为空\n");
    }
    if(-1 == is_full(q))
    {
        printf("队列已满");
    }
    else
    {
        printf("队列未满\n");
    }
    travel_queue(q);
    printf("%d\n", out_queue(q));
    printf("%d\n", out_queue(q));
    printf("%d\n", out_queue(q));

    return 0;
}
