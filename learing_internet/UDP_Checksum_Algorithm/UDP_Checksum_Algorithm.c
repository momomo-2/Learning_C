/**
 * @file udp_checksum.c
 * @brief UDP 校验和（One's Complement Sum）计算与验证的完整演示
 *
 * 【算法原理】
 *   1. 将所有 16 比特字累加，产生的溢出位（第17位）回卷加到最低位；
 *   2. 对累加结果取反码（按位取反），即为校验和；
 *   3. 验证时：将所有字（含校验和）累加并回卷，若结果为 0xFFFF，则数据正确。
 *
 * 编译: gcc -o udp_checksum udp_checksum.c -Wall
 * 运行: ./udp_checksum
 */

#include <stdio.h>
#include <stdint.h>

/*======================== 核心函数 ========================*/

/**
 * @brief 将两个 16 位数相加，并处理溢出回卷
 *
 * 【为什么需要这个函数？】
 *   普通加法可能产生第 17 位进位，而 UDP 校验和要求把该进位
 *   "回卷"加到结果的低 16 位上。例如：
 *     0xFFFF + 0x0001 = 0x10000 → 回卷后 = 0x0001
 *
 * @param a 第一个 16 比特字
 * @param b 第二个 16 比特字
 * @return uint16_t 回卷后的 16 比特和
 */
static uint16_t ones_complement_add(uint16_t a, uint16_t b)
{
    /* 用 32 位变量暂存，以捕获可能的第 17 位溢出 */
    uint32_t sum = (uint32_t)a + (uint32_t)b;

    /*
     * 如果 sum > 0xFFFF，说明产生了溢出。
     * 溢出位就是 sum >> 16（值为 1），将其加回低 16 位。
     * 注意：回卷后理论上仍可能再次溢出，但在两个 16 位数相加时
     *       最多只溢出一次，所以这里一次处理即可。
     */
    if (sum > 0xFFFF)
    {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    return (uint16_t)sum;
}

/**
 * @brief 计算一组 16 比特字的 UDP 校验和
 *
 * @param words     指向 16 比特字数组的指针
 * @param num_words 数组中字的个数
 * @return uint16_t 校验和（已取反码）
 */
static uint16_t calc_udp_checksum(const uint16_t *words, size_t num_words)
{
    uint16_t sum = 0;

    /* 第一步：逐字累加，每次加法都处理溢出回卷 */
    for (size_t i = 0; i < num_words; i++)
    {
        sum = ones_complement_add(sum, words[i]);
    }

    /* 第二步：对累加结果取反码（~ 运算符即按位取反） */
    /* 注意：C 语言的 ~ 作用于 uint16_t 时会自动提升为 int，
     *       因此需要强制截断回 16 位 */
    uint16_t checksum = (uint16_t)(~sum);

    return checksum;
}

/**
 * @brief 验证 UDP 校验和是否正确
 *
 * 【验证原理】
 *   将所有原始字 + 校验和字段一起累加（含回卷），
 *   若结果 == 0xFFFF，则说明传输无误。
 *   （等价于：累加后取反码 == 0x0000）
 *
 * @param words     原始 16 比特字数组
 * @param num_words 原始字的个数
 * @param checksum  待验证的校验和
 * @return int      1 = 校验通过, 0 = 校验失败
 */
static int verify_udp_checksum(const uint16_t *words, size_t num_words,
                               uint16_t checksum)
{
    uint16_t sum = 0;

    /* 把所有原始字累加 */
    for (size_t i = 0; i < num_words; i++)
    {
        sum = ones_complement_add(sum, words[i]);
    }

    /* 再把校验和也加进去 */
    sum = ones_complement_add(sum, checksum);

    /* 全 1 (0xFFFF) 表示校验通过 */
    return (sum == 0xFFFF) ? 1 : 0;
}

/*======================== 辅助打印函数 ========================*/

/**
 * @brief 以二进制形式打印一个 16 比特值（高位在前）
 */
static void print_binary16(uint16_t val)
{
    for (int i = 15; i >= 0; i--)
    {
        putchar((val & (1 << i)) ? '1' : '0');
        /* 每 4 位加一个空格，方便阅读 */
        if (i % 4 == 0 && i != 0)
            putchar(' ');
    }
}

/*======================== 主函数 ========================*/

int main(void)
{
    /*
     * 题目给定的 3 个 16 比特字（以十六进制存储）
     *   字1: 0110 0110 0110 0000 = 0x6660
     *   字2: 0101 0101 0101 0101 = 0x5555
     *   字3: 1000 1111 0000 1100 = 0x8F0C
     */
    uint16_t words[3] = {0x6660, 0x5555, 0x8F0C};
    size_t num_words = 3;

    printf("========== UDP 校验和计算演示 ==========\n\n");

    /* --- 打印原始数据 --- */
    printf("[原始数据]\n");
    for (size_t i = 0; i < num_words; i++)
    {
        printf("  字%zu: ", i + 1);
        print_binary16(words[i]);
        printf("  (0x%04X)\n", words[i]);
    }
    printf("\n");

    /* --- 计算校验和 --- */
    uint16_t checksum = calc_udp_checksum(words, num_words);

    printf("[计算过程]\n");
    printf("  步骤1: 字1 + 字2 = ");
    uint16_t step1 = ones_complement_add(words[0], words[1]);
    print_binary16(step1);
    printf("  (0x%04X)\n", step1);

    printf("  步骤2: 上一步 + 字3 = ");
    uint16_t step2 = ones_complement_add(step1, words[2]);
    print_binary16(step2);
    printf("  (0x%04X)\n", step2);

    printf("  步骤3: 取反码 → 校验和 = ");
    print_binary16(checksum);
    printf("  (0x%04X)\n\n", checksum);

    /* --- 验证校验和 --- */
    int valid = verify_udp_checksum(words, num_words, checksum);
    printf("[验证结果]\n");
    printf("  所有字 + 校验和 累加 = ");
    /* 手动展示验证时的累加结果 */
    uint16_t verify_sum = step2;
    verify_sum = ones_complement_add(verify_sum, checksum);
    print_binary16(verify_sum);
    printf("  (0x%04X)\n", verify_sum);
    printf("  校验%s ✅\n\n", valid ? "通过" : "失败 ❌");

    /* --- 模拟错误检测 --- */
    printf("[错误检测演示]\n");
    printf("  假设字2在传输中变为 0x5554（最低位翻转）...\n");
    uint16_t corrupted_words[3] = {0x6660, 0x5554, 0x8F0C};
    int corrupted_valid = verify_udp_checksum(corrupted_words, num_words, checksum);
    printf("  使用原校验和验证 → 校验%s\n",
           corrupted_valid ? "通过（未检测到错误）" : "失败 ❌（成功检测到错误！）");

    printf("\n========================================\n");

    return 0;
}