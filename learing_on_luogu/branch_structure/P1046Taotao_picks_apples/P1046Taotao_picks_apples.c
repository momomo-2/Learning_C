#include <stdio.h>

int apple[10];
int n = 0;
int h, i;
int main()
{
    for (i = 0; i < 10; i++)
    {
        scanf("%d ", &apple[i]);
    }
    scanf("%d", &h);

    for (i = 0; i < 10; i++)
    {
        if (apple[i] <= h + 30)
        {
            n += 1;
        }
    }

    printf("%d", n);

    return 0;
}
