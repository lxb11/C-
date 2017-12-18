/*************************************************************************
	> File Name: skiplist.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 15时22分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

#define MAX 6

typedef int datatype;
typedef struct node
{
    datatype data;
    struct node * next[0];
}Node;

int rand_level(int max)//产生随机数
{
    time_t ts;
    srand((unsigned int)time(&ts));
    int k = 0;
    while(rand() % 2)
    {
        ++k;
    }

    if(k > (MAX - 1))
    {
        return (MAX - 1);
    }
    else
    {
        return k;
    }

}

Node * insert_head(Node *head, datatype value)//升序排列插入
{
    int level = 0;
    level = rand_level(MAX);

    Node * node = (Node*)malloc(sizeof(Node) + (level + 1) * sizeof(Node *));//申请空间
    node->data = value;
    
    for(int i = 0; i <= level; ++i)
    {
        Node *temp = head;//保存head

        node->next[i] = NULL;//初始化node

        if(NULL == temp->next[i])//链表为空，直接插入
        {
            temp->next[i] = node;
        }
        else if(NULL != temp->next[i])//有数据，进行判断，升序插入
        {
            while((temp->next[i])->data < node->data)//查找出比value大的结点的前一个结点
            {
                temp = temp->next[i];
                if(NULL == temp->next[i])//跳出循环
                {
                    break;
                }
            }
            node->next[i] = temp->next[i];//在比value大的前一个结点的后面插入node，保持升序
            temp->next[i] = node;
        }
    }
    return head;
}

void *print_skiplist(Node *head)//显示
{
    for(int i = (MAX - 1); i >= 0; --i)
    {
        Node *temp = head->next[i];
        printf("第%d层:\t",i);
        while(NULL != temp)
        {
            printf("%d----->", temp->data);
            temp = temp->next[i];
        }
        putchar(10);
    }
}

void find_data(Node * head, datatype value)//查找元素
{
    Node * temp = head;
    for(int i = (MAX - 1); i >= 0; --i)//跳跃查找
    {
        if(NULL == temp->next[i])//次层无数据时进入下一层
        {
            continue;
        }
        while((temp->next[i])->data < value)//循环找出比value大的结点的前一个结点
        {
            temp = temp->next[i];
            if(NULL == temp->next[i])//temp后面无数据进入下一层
            {
                break;
            }
        }
        if(NULL != temp->next[i] && value == (temp->next[i])->data)//temp后面有数据，且value相等，查找到退出
        {
            printf("查到元素为: %d\n", (temp->next[i])->data);
            return;
        }
    }
    printf("未查找到\n");
}

Node *del_data(Node * head, datatype value)//删除元素，相同结点删除全部删除
{
    for(int i = (MAX - 1); i >= 0; --i)
    {
        Node *temp = head;
        while(NULL != temp->next[i])//循环跳跃找到膳删除的结点
        {
            if(value == (temp->next[i])->data)
            {
                if(0 == i)
                {
                    free(temp->next[i]);//free一次即可
                }
                temp->next[i] = (temp->next[i])->next[i];
                while(NULL != temp->next[i] && value == (temp->next[i])->data)//向后检查相同元素，删除
                {
                    temp->next[i] = (temp->next[i])->next[i];
                }
            }
            if(NULL != (temp->next[i]))
            {
                temp = temp->next[i];
            }
        }
    }
    return head;
}

int main()
{
    Node * head = (Node*)malloc(sizeof(Node) + MAX * sizeof(Node *));
    head->data = 0;
    for(int i = 0; i < MAX; ++i)
    {
        head->next[i] = NULL;
    }

    while(1)//循环插入
    {
        int value = 0;
        scanf("%d", &value);
        if(0 == value)
        {
            break;
        }
        head = insert_head(head, value);
    }

    print_skiplist(head);//显示skiplist

    printf("输入你要查找的数据\n");//查找元素
    int value;
    scanf("%d", &value);
    find_data(head, value);
    printf("输入你要删除的数据\n");//删除
    scanf("%d", &value);
    head = del_data(head, value);

    print_skiplist(head);//显示删除元素后skiplist
    return 0;
}
