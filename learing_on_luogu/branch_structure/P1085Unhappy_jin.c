/**
 * @file P1085Unhappy_jin.c
 * @author momomo
 * @brief test
 * @version 0.1
 * @date 2026-06-23
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>

int max = 0, day = 0;
int a, b;

int main()
{
    int i;

    for (i = 1; i <= 7; i++)
    {
        scanf("%d %d", &a, &b);
        if (a + b > 8)
        {
            if (max < a + b)
            {
                day = i;
                max = a + b;
            }
        }
    }
    printf("%d", day);

    return 0;
}