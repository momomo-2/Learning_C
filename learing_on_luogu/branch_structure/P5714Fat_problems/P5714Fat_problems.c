/**
 * @file P5714Fat_problems.c
 * @author momomo
 * @brief
 * @version 0.1
 * @date 2026-06-20
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>

int main()
{
    float m, h, bmi;
    scanf("%f %f", &m, &h);
    bmi = m / (h * h);
    if (bmi < 18.5)
    {
        printf("Underweight");
    }
    else
    {
        if (bmi < 24)
        {
            printf("Normal");
        }
        else
        {
            printf("%.6g\nOverweight", bmi);
        }
    }
    return 0;
}
