#include<stdio.h>
typedef struct stu
{
    char name[10];
    char gender[7];
    int age;
    int height;
} stu;
int main(void)
{
    stu a = {"정미애", "여성", 46, 167};
    stu* a_ptr  = &a;
    printf("%s %s %d %d\n", a_ptr->name, a_ptr->gender, a_ptr->age, a_ptr->height);
    return 0;
}