/*
 * C 语言格式说明符完全指南与实践
 *
 * 本文档旨在提供一个全面、实用的 C 语言格式说明符参考，
 * 适用于初学者和需要快速查阅的开发者。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    printf("=== C 语言格式说明符完全指南与实践 ===\n\n");

    // --- 第一部分：核心基础格式说明符 ---
    printf("--- 第一部分：核心基础格式说明符 ---\n");
    char my_char = 'A';
    char my_string[] = "Hello Kali";
    int my_int = -42;
    unsigned int my_uint = 42;
    float my_float = 3.14159f;
    double my_double = 3.141592653589793;

    printf("%%c (Character): '%c'\n", my_char);
    printf("%%s (String): %s\n", my_string);
    printf("%%d (Decimal int): %d\n", my_int);
    printf("%%i (Integer int, same as %%d): %i\n", my_int);
    printf("%%u (Unsigned int): %u\n", my_uint);
    printf("%%f (Float, default 6 decimals): %f\n", my_float);
    printf("%%lf (Double, for scanf must use 'l'): %lf\n", my_double);
    printf("%%e (Scientific notation): %e\n", my_float);
    printf("%%E (Scientific notation, uppercase E): %E\n", my_float);
    printf("%%g (General, smart format): %g\n", my_float);
    printf("%%G (General, uppercase E if scientific): %G\n", my_double);
    printf("\n");

    // --- 第二部分：进制与指针说明符 ---
    printf("--- 第二部分：进制与指针说明符 ---\n");
    unsigned int hex_val = 255;
    int oct_val = 64; // 实际值是 64
    int *ptr = &my_int;

    printf("%%o (Octal): %o (for value %d)\n", oct_val, oct_val);
    printf("%%x (Hexadecimal, lowercase): %x (for value %d)\n", hex_val, hex_val);
    printf("%%X (Hexadecimal, uppercase): %X (for value %d)\n", hex_val, hex_val);
    printf("%%p (Pointer address): %p (address of my_int)\n", (void *)ptr);
    printf("\n");

    // --- 第三部分：特殊说明符 ---
    printf("--- 第三部分：特殊说明符 ---\n");
    printf("To print a literal percent sign: 50%%\n");
    int chars_printed;
    printf("Using %%n to count printed chars: Hello%n\n", &chars_printed);
    printf("Number of characters printed before %%n: %d\n", chars_printed);
    printf("\n");

    // --- 第四部分：格式控制修饰符 ---
    printf("--- 第四部分：格式控制修饰符 ---\n");
    int val = 42;
    float fval = 3.14159f;
    char sval[] = "Kali";

    // 标志
    printf("Right-aligned (default): '%10d'\n", val);
    printf("Left-aligned (with -): '%-10d'\n", val);
    printf("Force sign (with +): %+d\n", val);
    printf("Force sign for positive: %+d\n", abs(val));
    printf("Pad with zeros (with 0): %010d\n", val);
    printf("Alternative form %%#x: %#x\n", hex_val);

    // 精度
    printf("Precision for float (2 decimal places): %.2f\n", fval);
    printf("Precision for integer (min width 5, pad with 0): %.5d\n", val);
    printf("Precision for string (max 3 chars): %.3s\n", sval);

    // 长度修饰符
    long my_long = 1234567890L;
    long long my_llong = 9223372036854775807LL;
    size_t my_size = sizeof(my_double);

    printf("Long int (%%ld): %ld\n", my_long);
    printf("Long long int (%%lld): %lld\n", my_llong);
    printf("Size_t (%%zu): %zu bytes\n", my_size);
    printf("\n");

    // --- 第五部分：实战速查与常见“坑”点 ---
    printf("--- 第五部分：实战速查与常见“坑”点 ---\n");
    double input_double;
    float input_float;

    printf("IMPORTANT: When using scanf for doubles, you MUST use %%lf.\n");
    printf("Example: scanf(\"%%lf\", &my_double_variable);\n");
    printf("For floats, use %%f in scanf.\n");
    printf("\n");

    printf("BEWARE: scanf(\"%%s\", str) stops reading at spaces.\n");
    printf("Use fgets(str, sizeof(str), stdin); for strings with spaces.\n");
    printf("\n");

    printf("SAFETY TIP: Always use format specifiers like printf(\"%%s\", str)\n");
    printf("instead of printf(str) to avoid format string vulnerabilities.\n");
    printf("\n");

    printf("=== 文档结束 ===\n");
    printf("\n");
    printf("在 Kali Linux 环境中，建议使用以下命令编译以获得更好的错误检查：\n");
    printf("gcc -Wall -Wformat your_file.c -o your_program\n");

    return 0;
}
