/*************************************************************************
	> File Name: set_juzhen.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月20日 星期四 19时42分47秒
 ********************************************************************/

#include<stdio.h>
void set_juzhen(int a[],int n);

int main()
{
    int a[] = {5,1,8,6,9};
    int n = sizeof(a) / sizeof(int);

    set_juzhen(a,n);
    return 0;
}

void set_juzhen(int a[],int n)
{
    int N = 2*n - 1;
    int M = N;
    int i = 0;
    int j = 0;
    int b[N][N];
    
    while(N > M / 2)
    {

        for(i = M - N; i < N; i++)
        {
            b[M-N][i] = a[j];
            b[i][M-N] = a[j];
            b[N-1][i] = a[j];
            b[i][N-1] = a[j];
        }
        N--;
        j++;
    }

    for(int i = 0; i < M; i++)
    {
        for(int k = 0; k < M; k++)
        {
            printf("%-2d",b[i][k]);
        }
        putchar(10);
    }
}
