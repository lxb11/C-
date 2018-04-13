/*************************************************************************
	> File Name: pqueue.h
	> Author: 
	> Mail: 
	> Created Time: 2018年04月06日 星期五 16时59分33秒
 ************************************************************************/

#ifndef _PQUEUE_H
#define _PQUEUE_H

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

typedef struct item
{
    datatype data;//数据
    int prio;//优先级，值越小，优先级越高
}Item;

typedef struct pqnode
{
    Item item;
    struct pqnode *next;
}PQNode;

typedef struct 
{
    PQNode *front, *rear;
}PQueue;

PQueue *init_queue();//初始化队列(带头结点的)
void push(PQueue *q, Item item);//入队，从队尾入
int  is_empty(PQueue *q);//判段队列是否为空
void pop(PQueue *q, Item *item);//出队，从队首出
int get_queue_len(PQueue *q);// 获取队列长度
void show_queue(PQueue *q);//输出队列所有元素
int is_empty(PQueue *q);//判段队列是否为空
void get_front(PQueue *q);//获取对首元素
void destory_queue(PQueue *q);//销毁队列

#endif
