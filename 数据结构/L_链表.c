/*************************************************************************
	> File Name: L_链表.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月23日 星期六 14时38分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct node
{
    ElementType data;//data为结点的数据信息
    struct node *next;//next为指向后继结点的指针

}Node;

typedef Node * List;

//创建空链表
Node * MakeEmpty()
{
    List Head = (List)malloc(sizeof(Node));
    if(Head == NULL)
    {
        printf("申请内存失败\n");
        return NULL;
    }
    Head->data = 0;
    Head->next = NULL;
    return Head;
}
//打印链表
void PrintList(List L)
{
    while(L->next != NULL)
    {
        L = L->next;
        printf("%d\t",L->data);
    }
    printf("\n");
}
//尾插链表
Node* InsertTail(List L, ElementType e)
{
    Node *temp = (List)malloc(sizeof(Node));
    temp->data = e;
    temp->next = NULL;
    Node *p = L;

    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return L;
}
//头插链表
Node* InsertHead(List L,ElementType e)
{
    Node *temp = (List)malloc(sizeof(Node));
    temp->data = e;
    temp->next = NULL;

    Node *p = L;
    p = p->next;
    L->next = temp;
    (L->next)->next = p;

    return L;
}
//头插链表（无返回值）
void INsertHead(List *L, ElementType e)
{
    Node *temp = (List)malloc(sizeof(Node));
    temp->data = e;
    temp->next = NULL;

    Node *p = *L;
    p = p->next;
    (*L)->next = temp;
    ((*L)->next)->next = p;

}
//删除某个元素
Node * DeleteNode(List L, ElementType e)
{
    Node * p = L;
    while((p->next)->data != e)
    {
        p = p->next;

    }
    if((p->next)->data = e)
    {
        p->next = (p->next)->next;
    }
    return L;
}
//找到元素位置
Node * FindElementType(List L, ElementType e)
{
    Node *p = L;
    while(p->data != e)
    {
        p = p->next;
    }
    return p;

}

int main()
{

    Node* list = MakeEmpty();
    list = InsertTail(list, 10);
    list = InsertHead(list, 11);
    list = InsertHead(list, 12);
    list = InsertHead(list, 13);
    
    INsertHead(&list, 14);
    PrintList(list);
    
    list = DeleteNode(list, 11);
    PrintList(list);
    Node * p = FindElementType(list, 14);
    printf("%d\n",p->data);


    return 0;
}
