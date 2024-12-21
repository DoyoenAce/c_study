void ShowData(const int*ptr)
{
    int*rptr = ptr;
    printf("%d \n", *rptr);
    *rptr = 20;
}
int main(void)
{
    int num = 10;
    int * ptr = &num;
    ShowData(ptr);
    return 0;
}