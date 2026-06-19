/**
 * @file P5712Apples.c
 * @author momomo
 * @brief
 * @version 0.1
 * @date 2026-06-19
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    if (x <= 1)
    {
        printf("Today, I ate %d apple.", x);
    }
    else
    {
        printf("Today, I ate %d apples.", x);
    }
}