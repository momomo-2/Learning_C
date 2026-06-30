/**
 * @file P1909Buy_pencils.c
 * @author momomo
 * @brief 洛谷P1909买铅笔问题 - 比较三种不同包装铅笔的价格,找出最便宜的购买方案
 * @version 0.1
 * @date 2026-06-23
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>

/**
 * @brief 计算价格
 *
 * @param a 总数
 * @param b 单盒数
 * @param c 单盒价格
 * @return int
 */
int price_calculation(int a, int b, int c)
{
    if (a % b != 0)
    {
        return (a / b + 1) * c;
    }
    else
    {
        return a / b * c;
    }
}

int main()
{
    int n;
    int price_min = 100000000;
    int num_single;
    int price_single;

    scanf("%d", &n);

    int i;
    for (i = 0; i < 3; i++)
    {
        scanf("%d %d", &num_single, &price_single);
        if (price_calculation(n, num_single, price_single) < price_min)
        {
            price_min = price_calculation(n, num_single, price_single);
        }
    }
    printf("%d", price_min);

    return 0;
}
