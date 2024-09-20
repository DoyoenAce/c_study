#include<stdio.h>
int main(void)
{
    char word[1000001];
    int alphabet[26] = {0, };
    scanf("%s", word);
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
            word[i] -= 32;
        alphabet[word[i] - 65]++;
    }
    int max = alphabet[0];
    int flag = 0;
    for (int i = 0; i < 26; i++)
        if (max < alphabet[i])
        {
            max = alphabet[i];
            flag = i;
        }
    int cnt = 0;
    for (int i = 0; i < 26; i++)
        if (max == alphabet[i])
            cnt++;
    if (cnt == 1)
        printf("%c", flag + 65);
    else
        printf("?");
    return 0;
}

