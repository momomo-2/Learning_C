#include <stdio.h>

int main()
{
    int n, k, i, a_sum = 0, b_sum = 0, a = 0, b = 0;
    scanf("%d %d", &n, &k);
    for (i = 1; i < n + 1; i++)
    {
        if (i % k == 0)
        {
            a_sum += i;
            a += 1;
        }
        else
        {
            b_sum += i;
            b += 1;
        }
    }
    float a_average = (float)a_sum / a;
    float b_average = (float)b_sum / b;
    printf("%.1f %.1f", a_average, b_average);

    return 0;
}
