#include <stdio.h>

// 函数声明
void shell_sort(int arr[], int len);

int main()
{
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = sizeof(arr) / sizeof(arr[0]); // 计算数组长度

    shell_sort(arr, len); // 调用希尔排序函数

    // 打印排序后的数组
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// 希尔排序函数
void shell_sort(int arr[], int len)
{
    // 计算初始间隔
    for (int gap = len / 2; gap > 0; gap /= 2)
    {
        // 对每个间隔进行插入排序
        for (int i = gap; i < len; i++)
        {
            int temp = arr[i]; // 当前待插入的元素
            int j = i;
            // 移动大于temp的元素
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp; // 插入元素到正确位置
        }
    }
}