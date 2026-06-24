/**
 * @file P5717Triangle_Classification.c
 * @author momomo
 * @brief Triangle_Classification
 * @version 0.1
 * @date 2026-06-24
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // 输入验证：边长必须为正数
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("Not triangle\n");
        return 0;
    }

    int num[3] = {a, b, c};

    // 完整的冒泡排序，确保 num[0] >= num[1] >= num[2]
    int i, j, mid;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2 - i; j++)
        {
            if (num[j] < num[j + 1])
            {
                mid = num[j];
                num[j] = num[j + 1];
                num[j + 1] = mid;
            }
        }
    }

    // 使用排序后的值进行判断
    int max_side = num[0];
    int mid_side = num[1];
    int min_side = num[2];

    // 三角形构成条件：任意两边之和大于第三边（只需检查最小两边之和是否大于最大边）
    if (max_side >= mid_side + min_side)
    {
        printf("Not triangle\n");
    }
    else
    {
        // 使用 long long 避免整数溢出
        long long max_sq = (long long)max_side * max_side;
        long long mid_sq = (long long)mid_side * mid_side;
        long long min_sq = (long long)min_side * min_side;

        if (max_sq == mid_sq + min_sq)
        {
            printf("Right triangle\n");
        }
        else if (max_sq < mid_sq + min_sq)
        {
            printf("Acute triangle\n");
        }
        else
        {
            printf("Obtuse triangle\n");
        }

        if (max_side == mid_side || max_side == min_side || mid_side == min_side)
        {
            printf("Isosceles triangle\n");
        }
        if (max_side == mid_side && mid_side == min_side)
        {
            printf("Equilateral triangle\n");
        }
    }

    return 0;
}
