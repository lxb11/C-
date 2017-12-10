/*************************************************************************
	> File Name: hash.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 10时49分02秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#define SIZE 5

int hash(int data)// hash函数 mod
{
    return data % SIZE;
}

int find(int data, int *a)//查找
{
    int key = hash(data);
    int count = 0;
    while(data != a[key] && SIZE != count)
    {
        key = hash(key + 1);
        ++count;
    }
    if(SIZE == count)
    {
        return -1;
    }
    else
    {
        return key;
    }

}

int main()
{
    int a[SIZE] = {0}; //存放数据的数组
    bzero(a, SIZE); //置零

    printf("输入%d个整型数字（回车隔开）\n", SIZE);
    for(int i = 0; i < SIZE; ++i)
    {
        int data;
        scanf("%d",&data);
        int key = hash(data);
        while(0 != a[key])
        {
            key = hash(key + 1);
        }
        a[key] = data;
    }
    
    for(int i = 0; i < SIZE; ++i)
    {
        printf("%d\t", a[i]);
    }

    printf("\n请输入你要查找的数\n");
    int data = 0;
    scanf("%d", &data);
    if(-1 == find(data, a))
    {
        printf("无此数据\n");
    }
    else
    {
        printf("%d\n", a[find(data, a)]);
    }
    putchar(10);
    return 0;
}
