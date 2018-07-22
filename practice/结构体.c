/*************************************************************************
	> File Name: 结构体.c
	> Author: 
	> Mail: 
	> Created Time: 2017年08月29日 星期二 17时16分01秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define man 0
#define woman 1

typedef struct Person
{ 
    char Name[50];
    _Bool Sex;
    int Age;
}Pers;

typedef struct Student
{
    struct Person per;
    enum Edu_typ{primary = 1, middle, high, university}Edu;
    int (*tgetEdu)(struct Student);          //函数指针
    int (*tsetEdu)(int a,int *b);
    int (*tprintStudent)(struct Student);
}Stud;

int getEdu(Stud a)
{

    printf("%d\n", a.Edu);
    return 0;
}

int setEdu(int a,int *b)
{
    
    *b = a;
    return 0;
}

int printStudent(Stud a)
{
    printf("Student姓名 = %s\t性别 = %d\t年龄 = %d\t学历 = %d\n",a.per.Name,a.per.Sex,a.per.Age,a.Edu);
    return 0;
}

int main()
{
    Stud u = {"lvzhao", man, 21, high};//给 u 初始化
    u.tgetEdu = getEdu;                // 函数指针的赋值方式
    u.tsetEdu = setEdu;
    u.tprintStudent = printStudent;  

    int *p = (int *)&u.Edu;
    u.tprintStudent(u);               //打印u的信息
    u.tsetEdu(university,p);          //修改一项属性
    u.tprintStudent(u);               //打印信息


    return 0;
}
