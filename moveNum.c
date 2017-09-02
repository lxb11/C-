/*************************************************************************
	> File Name: moveNum.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月18日 星期二 16时59分58秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(array) / sizeof(int);

    array[n] = array[0];
    for(int i = 0; i < n; i++)
    {
        array[i] = array[i+1];
    }
    for(int i = 0; i < n; i++)
    {
        printf("%-4d",array[i]);
    }

    return 0;
}
