/**
 * @file P5711Leap_year_check.c
 * @author momomo
 * @brief 闰年判断
 * @version 0.1
 * @date 2026-06-19
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>

/*
 * @brief 主函数
 * @return int*/
int main()
{
    int year;
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    return 0;
}