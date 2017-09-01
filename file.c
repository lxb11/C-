/*************************************************************************
	> File Name: file.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月06日 星期六 14时56分55秒
 ************************************************************************/

#include<stdio.h>
int main(int argc,char *argv[])
{
    FILE *fd;
    char *ch;

    if((fd = fopen(argv[1],"w")) == NULL)
    {
        printf("Open file error\n");
        return 0;
    }

    /*while(ch != '$')
    {
        fputc(ch,fd);
        ch = getchar();
    }

    while((ch = fgetc(fd)) != EOF)
    {
        putchar(ch);
    }//以文本方式输出文件
    */

    gets(ch);
    while(*ch++ != '$')
    {
        fputs(ch.fd);
        gets(ch);

    }
    fclose(fd);

    return 0;
}
