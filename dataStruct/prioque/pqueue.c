/*************************************************************************
	> File Name: pqueue.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月07日 星期六 11时36分16秒
 ************************************************************************/

#include"pqueue.h"

PQueue *init_queue()//初始化队列(带头结点的)
{
    PQueue *q = (PQueue*)malloc(sizeof(PQueue));//申请链队列的头尾指针
    PQNode *p = (PQNode*)malloc(sizeof(PQNode));//申请连队连头结点
    
    if(NULL == q || NULL == p)
    {
        printf("初始化失败\n");
        return NULL;
    }

    p->next = NULL;//头结点的next指针置为空
    q->front = p;
    q->rear = p;
    printf("初始化成功\n");
    return q;
}

/*void push(PQueue *q, Item item)//入队，从队尾入
{
    PQNode *temp = (PQNode*)malloc(sizeof(PQNode));//申请新连队列结点
    temp->item.data = item.data;
    temp->item.prio = item.prio;
    temp->next = NULL;//新结点×temp作为队尾结点时其next域为空
    q->rear->next = temp;//将新结点×p链到原队尾结点之后
    q->rear = temp;
    printf("入队成功\n");
}*/

void push(PQueue *q, Item item)//入队，优先级数小，优先级越高，相同优先级，按先后顺序入队
{
    PQNode *temp = (PQNode*)malloc(sizeof(PQNode));
    temp->item.data = item.data;
    temp->item.prio = item.prio;
    temp->next = NULL;
    PQNode *seek = q->front->next;
    if(NULL == seek)//仅有头结点空队列
    {
        q->front->next = temp;
        q->rear = temp;
        printf("1入队成功\n");
        return;
    }
    else
    {
        if(NULL == seek->next)//插入到尾部
        {
            seek->next = temp;
            q->rear = temp;
            printf("2入队成功\n");
            return;
        }
        else
        {
            while(seek->next->item.prio <= temp->item.prio)//寻找优先级一样的最后结点
            {
                seek = seek->next;
                if(NULL == seek->next)//插入到尾部
                {
                    seek->next = temp;
                    q->rear = temp;
                    printf("2入队成功\n");
                    return;
                }
            }
            temp->next = seek->next;
            temp = seek->next;//在中间插入
            printf("3入队成功\n");
            return;
        }
    }
}

int is_empty(PQueue *q)//判段队列是否为空
{
    if(q->front == q->rear)
    {
        return -1;//队空
    }
    else
    {
        return 0;//队不空
    }
}

void pop(PQueue *q, Item *item)//出队，从队首出
{
    PQNode *temp;
    if(is_empty < 0)
    {
        printf("队空\n");
        return;
    }
    else
    {
        temp = q->front->next;//指针temp指向连队列第一个数据结点
        q->front->next = temp->next;//头结点的next指针指向队列第二个数据结点
        *item = temp->item;
        free(temp);
        if(NULL == q->front->next)//出队后为空，则置为空队列
        {
            q->rear = q->front;
        }
    }
    printf("出队成功\n");
}

int get_queue_len(PQueue *q)// 获取队列长度
{
    int count = 0;
    PQNode *temp = q->front;
    while(NULL != temp->next)
    {
        temp = temp->next;
        ++count;
    }
    return count;

}

void show_queue(PQueue *q)//输出队列所有元素
{
    if(is_empty(q) < 0)
    {
        printf("队列为空\n");
        return;
    }
    else
    {
        PQNode *temp = q->front;
        while(NULL != temp->next)
        {
            printf("数据: %d\t优先级: %d\n", temp->next->item.data, temp->next->item.prio);
            temp = temp->next;
        }
    }
    
}

void get_front(PQueue *q)//获取对首元素
{
    if(is_empty(q) < 0)
    {
        printf("队列为空\n");
        return;
    }
    else
    {
        PQNode *temp = q->front;
        printf("队首元素：数据: %d\t优先级 %d\n", temp->next->item.data, temp->next->item.prio);
    }
}
void destory_queue(PQueue *q)//销毁队列,释放所有结点内存(保留头结点)
{
    while(NULL != q->front->next)
    {
        PQNode *temp = q->front->next;
        q->front->next = temp->next;
        free(temp);
    }
    q->rear = q->front;
}



int main()
{
    PQueue *q = init_queue();
    Item item;//测试用例,入队
    item.data = 2;
    item.prio = 0;
    push(q, item);
    Item item1;
    item1.data = 3;
    item1.prio = 1;
    push(q, item1);
    Item item2;
    item2.data = 4;
    item2.prio = 1;
    push(q, item2);
    Item item3;
    item3.data = 4;
    item3.prio = 0;
    push(q, item3);


    printf("队列长度为 %d\n", get_queue_len(q));
    printf("显示队列全部元素\n");
    show_queue(q);
    printf("队头元素\n");
    get_front(q);

    Item *i;
    pop(q, i);
    printf("出队\n");
    printf("data = %d\t prio = %d\n", i->data, i->prio);
    printf("销毁队列\n");
    destory_queue(q);
    if(is_empty(q) < 0)
    {
        printf("队列为空\n");
    }

    return 0;
}
