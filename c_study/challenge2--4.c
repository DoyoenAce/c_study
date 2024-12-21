#include<stdio.h>
void Pali(char*word)
{
    int len = 0;
    int num = 0;
    while(word[len] !=0)
    {
        len++
    }
    for(int i = 0; i<len/2; i++)
    {
        if(word[i] != word[len-i-1])
        {
            num += 1;
        }
    }
    if(num ==0){
        printf("회문입니다.");
    }
    else{
        printf("회문이 아닙니다.");
    }
    reutnr 0;
}