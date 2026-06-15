#include <stdio.h>

int main()
{
    // 我们想计算 100万 乘以 100万，结果应该是 1万亿
    // 1万亿超出了 int 的最大值(约21亿)，但 long long 完全装得下

    long long result1 = 1000000 * 1000000;     // ❌ 没加后缀
    long long result2 = 1000000LL * 1000000LL; // ✅ 加了 LL 后缀

    printf("没加后缀: %lld\n", result1);
    printf("加了后缀: %lld\n", result2);

    return 0;
}