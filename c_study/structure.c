#include<stdio.h>
typedef struct stu
{
    char name[10];
    char gender[7];
    int age, height;
    
} stu;
int main(void)
{
    //stu a = {"고일동", "여성", 15, 160};
    //stu* a_ptr = &a;
    //printf("%s %s %d %d\n", a_ptr->name, a_ptr->gender, a_ptr->age, a_ptr->height);
    stu stus[5] = {{"홍길동", "남성", 10, 150}, {"임도연", "남성", 13, 156}, {"홍긴동", "남성", 9, 135}, {"임도영", "여성", 14, 160}, {"고길동", "여성", 14, 160}};
    for(int i = 0; i < 5; i++)
    {
        printf("%s %s %d %d\n", stus[i].name, stus[i].gender, stus[i].age, stus[i].height);
    }
    return 0;
}