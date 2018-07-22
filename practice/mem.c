/*************************************************************************
	> File Name: mem.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月19日 星期五 21时49分04秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<assert.h>
void *my_memmove(void *dest,const void *src,size_t count);
void *my_memcpy(void *dest,const void *src,size_t count);

int main()
{
    char s1[] = "Golden Global View";
    char s2[] = "Golden Global View";

    my_memmove(s1,s1 + 7,strlen(s1) + 1 - 7);
    printf("%s\n",s1);
    my_memcpy(s2,s2 + 7,strlen(s2) + 1 - 7);
    printf("%s\n",s2);

    return 0;
}

void *my_memmove(void *dest,const void *src,size_t count)
{

    assert(dest != NULL || src != NULL);
    
    char *tmpdst = (char *)dest;
    char *tmpsrc = (char *)src;


    //从src的头向后复制
    if(tmpdst <= tmpsrc || tmpdst >= tmpsrc + count)
    {
        while(count--)
        {
            *tmpdst++ = *tmpsrc++;
        }
    }
    //从src的尾向前复制
    else
    {
        tmpdst = tmpdst + count - 1;
        tmpsrc = tmpsrc + count - 1;
        while(count--)
        {
            *tmpdst-- = *tmpsrc--;
        }
    }

    return dest; 
}

void *my_memcpy(void *dest,const void *src,size_t count)
{
    assert(dest != NULL || src != NULL);

    char *tmp = (char *)dest;
    char *p = (char *)src;

    while(count--)
    {
        *tmp++ = *p++;
    }
    return dest;
}
