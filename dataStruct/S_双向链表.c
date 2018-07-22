/*************************************************************************
	> File Name: S_双向链表.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月26日 星期二 15时08分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;

typedef struct Node
{
    ElementType data;//data为结点的数据信息
    struct Node *prior,*next;//prior，next分别为指向直接前驱和直接后继结点的指针

}Node;//双向链表结点类型


//创建空链表
Node * MakeEmpty()
{
    Node * Head = (Node *)malloc(sizeof(Node));
    if(Head == NULL)
    {
        printf("创建链表失败\n");
        return NULL;
    }
    Head->data = 0;
    Head->prior = NULL;
    Head->next = NULL;
    return Head; //返回头结点
}

//打印链表
void PrintList(Node * L)
{
    if(L->next == NULL)
    {
        printf("Error: 链表为空\n");
    }                                 //判断链表是否为空
    else
    {
        while(L->next != NULL)
        {
            L = L->next;
            printf("%d\t",L->data);
        }
        printf("\n");
    }                             //循环打印链表
}


//尾插链表
Node * InsertTail(Node * L, ElementType e)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = e;
    temp->prior = NULL;
    temp->next = NULL;
    
    Node *p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->prior = p;
    return L;
}

//头插链表
Node * InsertHead(Node * L, ElementType e)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = e;
    temp->prior = NULL;
    temp->next = NULL;

    temp->next = L->next;
    (L->next)->prior = temp;
    temp->prior = L;
    L->next = temp;
    return L;

}
//找出元素位置返回
Node * FindElementType(Node * L, ElementType e)
{
    Node *p = L;
    while(p->data != e)
    {
        p = p->next;
    }                  //找到该元素的结点
    return p;
}
//删除链表某个元素
void DeleteElementType(Node *L, ElementType e)
{
    while((L->next)->data != e)
    {
        L = L->next;
    }                 //找到删除元素的前一个结点

    L->next = (L->next)->next;  //前一个结点的后继指针指向删除元素的下一个结点
    (L->next)->prior = L;       //删除元素的下一个结点的前驱指针指向L
    //删除成功
}

//在a结点之后插入元素e
Node * InsertMid(Node *L, ElementType a, ElementType e)
{

    Node *p = L;

    while(p->data != a)
    {
        p = p->next;
    }            //找到a结点

    if(p->next == NULL)
    {
        printf("Error: a结点为最后一个结点\n");
        return L;
    }
    else
    {
        Node *temp = (Node *)malloc(sizeof(Node));//为元素e申请一个地址
        temp->data = e;
        temp->prior = NULL;
        temp->next = NULL;
        temp->prior = p;
        temp->next = p->next;
        (p->next)->prior = temp;
        p->next = temp;     //在a结点后插入e结点
        return L;
    }
}

//删除整个链表
Node * DeleteAll(Node * L)
{
    if(L->next == NULL)    //链表为空，无需处理
    {
        printf("Error: 链表为空，无需处理\n");
        return L;
    }
    else
    {
        Node *p = L;
        while(p->next != NULL)
        {
            p = p->next;
            free(p);
        }           //删除链表头结点后的所有结点
        L->next = NULL;
        L->prior = NULL;
        return L;
    }

}
int main()
{
    Node * list = MakeEmpty();
    list = InsertTail(list, 1);
    list = InsertTail(list, 2);
    list = InsertTail(list, 3);
    list = InsertTail(list, 4);
    list = InsertTail(list, 5) ; //尾插
    PrintList(list);
    list = InsertHead(list, 11); //头插
    PrintList(list);            //找结点并返回该结点
    printf("%d\n",(FindElementType(list, 2))->data);
    DeleteElementType(list, 2); //删除结点
    PrintList(list);
    list = InsertMid(list,3,99);//在某个结点后插入一个结点
    PrintList(list);
    list = InsertMid(list,1,99);
    PrintList(list);
    list = DeleteAll(list);
    PrintList(list);


    return 0;
}
