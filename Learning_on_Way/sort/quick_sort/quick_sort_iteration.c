#include <stdio.h>

// 范围结构体
typedef struct _Range
{
    int start, end;
} Range;

// 创建新的范围
Range new_Range(int s, int e)
{
    Range r;
    r.start = s;
    r.end = e;
    return r;
}

// 交换两个整数
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// 快速排序函数
void quick_sort(int arr[], const int len)
{
    if (len <= 0)
        return; // 避免 len 等于负值时引发段错误（Segment Fault）

    Range r[len];
    int p = 0;
    r[p++] = new_Range(0, len - 1);

    while (p > 0)
    {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;

        int mid = arr[(range.start + range.end) / 2]; // 选取中间点为基准点
        int left = range.start, right = range.end;

        do
        {
            while (arr[left] < mid)
                ++left; // 检测基准点左侧是否符合要求
            while (arr[right] > mid)
                --right; // 检测基准点右侧是否符合要求

            if (left <= right)
            {
                swap(&arr[left], &arr[right]);
                left++;
                right--; // 移动指针以继续
            }
        } while (left <= right);

        if (range.start < right)
            r[p++] = new_Range(range.start, right);
        if (range.end > left)
            r[p++] = new_Range(left, range.end);
    }
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