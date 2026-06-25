#include <stdio.h>

// 交换两个整数
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// 递归实现快速排序
void quick_sort_recursive(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int mid = arr[end];
    int left = start, right = end - 1;

    while (left < right)
    {
        while (left < right && arr[left] < mid)
            left++;
        while (left < right && arr[right] >= mid)
            right--;
        swap(&arr[left], &arr[right]);
    }

    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;

    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

// 快速排序入口函数
void quick_sort(int arr[], int len)
{
    quick_sort_recursive(arr, 0, len - 1);
}

int main()
{
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = sizeof(arr) / sizeof(arr[0]); // 计算数组长度

    quick_sort(arr, len); // 调用快速排序函数

    // 打印排序后的数组
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}