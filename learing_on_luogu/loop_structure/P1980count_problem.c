#include <stdio.h>

int main()
{
    int n, x, count = 0;
    scanf("%d %d", &n, &x); // 注意：x 改为用 %d 读入整数

    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (temp > 0)
        {
            if (temp % 10 == x) // 取最低位比较
                count++;
            temp /= 10; // 去掉最低位
        }
    }

    printf("%d\n", count);
    return 0;
}
