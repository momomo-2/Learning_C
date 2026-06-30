/**
 * @file P5716Numbers_of_days_in_a_month.c
 * @author momomo
 * @brief return Numbers_of_days_in_a_month
 * @version 0.1
 * @date 2026-06-23
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>

int leap_year[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int normal_year[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int year, month;

/**
 * @brief detect_leap?
 *
 * @return int
 */
int detect_leap()
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

int main()
{
    scanf("%d %d", &year, &month);

    if (detect_leap())
        printf("%d\n", leap_year[month - 1]);
    else
        printf("%d\n", normal_year[month - 1]);

    return 0;
}