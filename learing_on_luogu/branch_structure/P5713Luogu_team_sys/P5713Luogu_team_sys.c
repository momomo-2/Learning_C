/**
 * @file P5713Luogu_team_sys.c
 * @author momomo
 * @brief Luogu_team_sys
 * @version 0.1
 * @date 2026-06-19
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>

/**
 * @brief main
 *
 * @return char
 */
int main()
{
    int n;
    scanf("%d", &n);
    int local = 5 * n;
    int luogu = 11 + 3 * n;
    if (local > luogu)
        printf("Luogu");
    else
        printf("Local");

    return 0;
}