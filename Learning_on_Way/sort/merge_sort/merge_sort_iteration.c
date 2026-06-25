#include <stdio.h>
#include <stdlib.h>

// 函数声明
int min(int x, int y);
void merge_sort(int arr[], int len);

int main()
{
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = sizeof(arr) / sizeof(arr[0]); // 计算数组长度

    merge_sort(arr, len); // 调用归并排序函数

    // 打印排序后的数组
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// 返回两个数中的最小值
int min(int x, int y)
{
    return x < y ? x : y;
}

// 归并排序函数
void merge_sort(int arr[], int len)
{
    int *a = arr;
    int *b = (int *)malloc(len * sizeof(int));

    if (b == NULL)
    { // 检查内存分配是否成功
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int seg = 1; seg < len; seg += seg)
    {
        for (int start = 0; start < len; start += seg + seg)
        {
            int low = start;
            int mid = min(start + seg, len);
            int high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;

            // 合并两个子数组
            while (start1 < end1 && start2 < end2)
            {
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }
            while (start1 < end1)
            {
                b[k++] = a[start1++];
            }
            while (start2 < end2)
            {
                b[k++] = a[start2++];
            }
        }

        // 交换数组指针
        int *temp = a;
        a = b;
        b = temp;
    }

    // 如果a和arr不相同，则将a的内容复制回arr
    if (a != arr)
    {
        for (int i = 0; i < len; i++)
        {
            b[i] = a[i];
        }
        b = a;
    }

    free(b); // 释放内存
}