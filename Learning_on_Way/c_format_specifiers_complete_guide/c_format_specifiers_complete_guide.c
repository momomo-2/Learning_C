/**
 * @file c_format_specifiers_complete_guide.c
 * @author momomo
 * @brief c_format_specifiers_complete_guide
 * @version 0.1
 * @date 2026-06-20
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // 打印标题
    printf("=== C 语言格式说明符完全指南与实践 ===\n\n");

    // --- 第一部分：核心基础格式说明符 ---
    printf("--- 第一部分：核心基础格式说明符 ---\n");

    // 声明测试变量
    char my_char = 'A';                   // 字符类型
    char my_string[] = "Hello Kali";      // 字符串
    int my_int = -42;                     // 有符号整数（负数）
    unsigned int my_uint = 42;            // 无符号整数
    float my_float = 3.14159f;            // 单精度浮点数
    double my_double = 3.141592653589793; // 双精度浮点数

    // 演示基础格式说明符
    printf("%%c (Character): '%c'\n", my_char);                          // %c: 输出单个字符
    printf("%%s (String): %s\n", my_string);                             // %s: 输出字符串
    printf("%%d (Decimal int): %d\n", my_int);                           // %d: 十进制有符号整数
    printf("%%i (Integer int, same as %%d): %i\n", my_int);              // %i: 整数（与%d相同）
    printf("%%u (Unsigned int): %u\n", my_uint);                         // %u: 无符号十进制整数
    printf("%%f (Float, default 6 decimals): %f\n", my_float);           // %f: 浮点数（默认6位小数）
    printf("%%lf (Double, for scanf must use 'l'): %lf\n", my_double);   // %lf: 双精度浮点数（scanf时必须用%lf）
    printf("%%e (Scientific notation): %e\n", my_float);                 // %e: 科学计数法（小写e）
    printf("%%E (Scientific notation, uppercase E): %E\n", my_float);    // %E: 科学计数法（大写E）
    printf("%%g (General, smart format): %g\n", my_float);               // %g: 通用格式（自动选择%f或%e）
    printf("%%G (General, uppercase E if scientific): %G\n", my_double); // %G: 通用格式（自动选择%f或%E）
    printf("\n");

    // --- 第二部分：进制与指针说明符 ---
    printf("--- 第二部分：进制与指针说明符 ---\n");

    // 声明进制和指针测试变量
    unsigned int hex_val = 255; // 十六进制测试值
    int oct_val = 64;           // 八进制测试值
    int *ptr = &my_int;         // 指向my_int的指针

    // 演示进制和指针格式说明符
    printf("%%o (Octal): %o (for value %d)\n", oct_val, oct_val);                  // %o: 八进制（无前导0）
    printf("%%x (Hexadecimal, lowercase): %x (for value %d)\n", hex_val, hex_val); // %x: 十六进制（小写字母）
    printf("%%X (Hexadecimal, uppercase): %X (for value %d)\n", hex_val, hex_val); // %X: 十六进制（大写字母）
    printf("%%p (Pointer address): %p (address of my_int)\n", (void *)ptr);        // %p: 指针地址（需转换为void*）
    printf("\n");

    // --- 第三部分：特殊说明符 ---
    printf("--- 第三部分：特殊说明符 ---\n");

    // 演示特殊格式说明符
    printf("To print a literal percent sign: 50%%\n");                      // %%: 输出百分号本身
    int chars_printed;                                                      // 用于存储%n记录的字符数
    printf("Using %%n to count printed chars: Hello%n\n", &chars_printed);  // %n: 记录已输出的字符数量
    printf("Number of characters printed before %%n: %d\n", chars_printed); // 显示%n记录的字符数
    printf("\n");

    // --- 第四部分：格式控制修饰符 ---
    printf("--- 第四部分：格式控制修饰符 ---\n");

    // 声明格式控制测试变量
    int val = 42;          // 整数测试值
    float fval = 3.14159f; // 浮点数测试值
    char sval[] = "Kali";  // 字符串测试值

    // 标志修饰符演示
    printf("Right-aligned (default): '%10d'\n", val);   // 右对齐（默认），宽度10
    printf("Left-aligned (with -): '%-10d'\n", val);    // 左对齐（使用-标志），宽度10
    printf("Force sign (with +): %+d\n", val);          // 强制显示正负号（使用+标志）
    printf("Force sign for positive: %+d\n", abs(val)); // 对正数强制显示+号
    printf("Pad with zeros (with 0): %010d\n", val);    // 用0填充（使用0标志），宽度10
    printf("Alternative form %%#x: %#x\n", hex_val);    // %#x: 十六进制带0x前缀

    // 精度修饰符演示
    printf("Precision for float (2 decimal places): %.2f\n", fval);         // %.2f: 浮点数保留2位小数
    printf("Precision for integer (min width 5, pad with 0): %.5d\n", val); // %.5d: 整数最小宽度5，不足补0
    printf("Precision for string (max 3 chars): %.3s\n", sval);             // %.3s: 字符串最多输出3个字符

    // 长度修饰符演示
    long my_long = 1234567890L;                 // 长整型
    long long my_llong = 9223372036854775807LL; // 长长整型
    size_t my_size = sizeof(my_double);         // size_t类型（sizeof返回值）

    printf("Long int (%%ld): %ld\n", my_long);         // %ld: 长整型
    printf("Long long int (%%lld): %lld\n", my_llong); // %lld: 长长整型
    printf("Size_t (%%zu): %zu bytes\n", my_size);     // %zu: size_t类型
    printf("\n");

    // --- 第五部分：实战速查与常见"坑"点 ---
    printf("--- 第五部分：实战速查与常见坑点 ---\n");

    // 声明输入测试变量
    double input_double; // 双精度浮点输入变量
    float input_float;   // 单精度浮点输入变量

    // scanf使用注意事项
    printf("IMPORTANT: When using scanf for doubles, you MUST use %%lf.\n"); // 重要：scanf读取double必须用%lf
    printf("Example: scanf(\"%%lf\", &my_double_variable);\n");              // 示例：scanf("%lf", &variable)
    printf("For floats, use %%f in scanf.\n");                               // scanf读取float使用%f
    printf("\n");

    // 字符串输入注意事项
    printf("BEWARE: scanf(\"%%s\", str) stops reading at spaces.\n");         // 警告：scanf("%s")遇到空格停止
    printf("Use fgets(str, sizeof(str), stdin); for strings with spaces.\n"); // 建议：用fgets读取含空格的字符串
    printf("\n");

    // 安全编程建议
    printf("SAFETY TIP: Always use format specifiers like printf(\"%%s\", str)\n"); // 安全提示：始终使用格式说明符
    printf("instead of printf(str) to avoid format string vulnerabilities.\n");     // 避免格式化字符串漏洞
    printf("\n");

    // 文档结束
    printf("=== 文档结束 ===\n");
    printf("\n");

    // 编译建议
    printf("在 Kali Linux 环境中，建议使用以下命令编译以获得更好的错误检查：\n");
    printf("gcc -Wall -Wformat your_file.c -o your_program\n");

    return 0;
}
