/*************************************************************************
	> File Name: hash1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 11时44分30秒
 ************************************************************************/

#include<stdio.h>
#include"L_链表.c"//包含链表的基本操作
#define SIZE 5

int hash(int data)//hash 函数 mod
{
    return data % SIZE;
}

int find(int data, Node **a)//查找数据并返回
{
    int key = hash(data);
    Node * p = FindElementType(a[key], data);
    if(NULL == p)
    {
        return -1;
    }
    else
    {
        return p->data;
    }
}

int main()
{
   Node * a[SIZE] = {NULL}; //存放数据的指针数组
   for(int i = 0; i < SIZE; ++i)
   {
       a[i] = MakeEmpty();//创建带头结点链表
   }

   printf("输入整型数字 (回车隔开) 0 结束\n");
   while(1)
   {
       int data;
       scanf("%d",&data);
       if(0 == data)
       {
           break;
       }
       int key = hash(data);
       a[key] = InsertHead(a[key], data);
   }

   for(int i = 0; i < SIZE; ++i)
   {
       PrintList(a[i]);
   }

   printf("%d\n", PrintLength(a[1]));
   printf("\n请输入你要查找的数\n");
   int data = 0;
   scanf("%d", &data);
   if(-1 == find(data, a))
   {
       printf("无此数据\n");
   }
   else
   {
       printf("数据查到：%d\n", find(data, a));
   }
   putchar(10);
   return 0;
}

