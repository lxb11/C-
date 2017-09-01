/*************************************************************************
	> File Name: copy.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月06日 星期六 16时55分25秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{

    FILE * fp1;
    FILE * fp2;
    fp1 = fopen(argv[1], "r");
    fp2 =  fopen(argv[2], " w+");
    char ch;
    while (ch = fgetc(fp1) != 0)
    {
         fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;


}
