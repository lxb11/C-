/*************************************************************************
	> File Name: strlen.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月06日 星期六 09时37分55秒
 ************************************************************************/

#include<stdio.h>
#include<assert.h>
int mstrcom(const char *str1,const char *str2);
unsigned int mstrlen(const char *str);
char *mstrcat(char *str1,const char *str2);
char *mstrncat(char *str1,const char *str2,int num);
char *mstrcpy(char *str1,const char *str2);
char *mstrncpy(char *str1,const char *str2,int n);

int main()
{
    char s1[20] = "hello";
    char *s2 = "i am hehe";

    printf("%d\n",mstrlen(s1));
    printf("%d\n",mstrcom(s1,s2));
    printf("%s\n",mstrcat(s1,s2));
    printf("%s\n",mstrncat(s1,s2,1));
    printf("%s\n",mstrcpy(s1,s2));
    printf("%s\n",mstrncpy(s1,s2,4));
    return 0;
}

unsigned int mstrlen(const char *str)
{
    assert(str != NULL);//加断言，不满足条件退出

    unsigned int len = 0;
    while(*str++ != 0)
    {
        len++;
    }
    return len;

}

int mstrcom(const char *str1,const char *str2)
{
    assert(str1 != NULL && str2 != NULL);

    while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
    {
        ++str1;
        ++str2;
    }
    return *str1 - *str2;
}


char *mstrcat(char *str1,const char *str2)
{
    assert(str1 != NULL && str2 != NULL);

    char *desstr = str1;
    while(*str1 != '\0')
    {
        str1++;
    }
    while(*str1++ = *str2++);
    return desstr;
}

char *mstrncat(char *str1,const char *str2,int num)
{
    char *address = str1;
    assert(str1 != NULL && str2 != NULL);

    while(*str1)
    {
        ++str1;
    }
    while(num -- && (*str1++ = *str2++));
    *str1 == '\0';
    return address;
}

char *mstrcpy(char *str1,const char *str2)
{
    assert(str1 != NULL && str2 != NULL);

    char * address = str1;
    while(*str1++ = *str2++);
    return address;
    
}

char *mstrncpy(char *str1,const char *str2,int n)
{
    assert(NULL != str1 && NULL != str2);
    char *temp = str1;
    while(n-- && (*str1++ = *str2++))
    {
        *str1 = '\0';
    }
    return temp;
    
}
