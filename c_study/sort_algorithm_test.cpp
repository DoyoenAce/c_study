#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
    int a[10] = {9, 3, 5, 6, 1, 2, 4, 8, 7, 10};
    sort(a, a+10);

    for(int i = 0; i  < 10; i++)
    {
        cout << a[i];
    }
}