/*************************************************************************
	> File Name: shi_zhuan_er.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月18日 星期二 20时43分08秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int a;
    int *b;
    int i = 0;

    printf("请输入一个十进制整数\n");
    scanf("%d",&a);

    while(a != 0)
    {
        *(b + i) = (a % 2);
        i++;
        a = a/2;
    }
          
    for(i; i >= 0; i--)
    {
        printf("%1d",b[i]);
    }
    putchar(10);
    return 0;
}
