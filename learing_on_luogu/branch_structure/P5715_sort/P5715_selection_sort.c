/**
 * @file P5715_selection_sort.c
 * @author momomo
 * @brief selection_sort
 * @version 0.1
 * @date 2026-06-21
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>

/// @brief C语言读取三个整数并展示排序
/// @return 排序
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int arr[3] = {a, b, c};
    for (int i = 0; i < 2; i++)
    {
        int k = i;
        for (int j = i + 1; j < 3; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            int m = 0;
            m = arr[i];
            arr[i] = arr[k];
            arr[k] = m;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
