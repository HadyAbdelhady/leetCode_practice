#include <stdio.h>
#include <string.h>

int longestPalindrome(char *s)
{

    int hash_map[58] = {0}, result = 0, odd = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        hash_map[s[i] - 'A']++;
    }

    for (int i = 0; i < 58; i++)
    {
        if (hash_map[i] % 2 == 0)
            result += hash_map[i];
        else
        {
            odd = 1;
            result += hash_map[i] - 1;
        }
    }
    return (odd) ? result + 1 : result;
}
void main()
{
    char *s = "hello";
    printf("%d", strlen(s));
}