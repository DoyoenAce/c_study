#include  <stdio.h>
int main（void）
{
    int arr[3]={0,  1,  2};
    printf（"베）열의       이름:  %p   \n",  arr）;
    printf（"첫       번째  요소:  %p   \n",   &arr[0]）;
    printf（"두      번째  요소:  %p   \n",   &arr[l]）;
    printf（"세        번째   요소:  %p   \n",   &arr[2]）;
          // am =  &arr[i];   // 이       문장은     컴파일      에러를     일으킨다.
    return 0;
}