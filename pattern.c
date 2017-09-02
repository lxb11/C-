/*************************************************************************
	> File Name: pattern.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月26日 星期日 09时13分44秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n = 5,i,j,k;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n - i;j++)
        printf(" ");
        for(k = 0;k <= 2*i;k++)
        printf("*");
        putchar(10);
    }
    return 0;
}
