#include <stdio.h>

// 函数声明
void insertion_sort(int arr[], int len);

int main()
{
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = sizeof(arr) / sizeof(arr[0]); // 计算数组长度

    insertion_sort(arr, len); // 调用插入排序函数

    // 打印排序后的数组
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// 插入排序函数
void insertion_sort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int temp = arr[i]; // 当前待插入的元素
        int j = i;
        // 向右移动大于temp的元素
        while (j > 0 && arr[j - 1] > temp)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp; // 插入元素到正确位置
    }
}
