/*
 * C语言输出映射完整示例程序
 * 编译命令: gcc -std=c99 output_mapping.c -o output_mapping
 * 运行命令: ./output_mapping
 *
 * 本程序完整展示了C语言printf函数的"输出映射"机制：
 * 1. 基本数据类型的格式映射
 * 2. 格式控制（宽度、精度、对齐）
 * 3. 特殊字符和转义序列
 * 4. 不同进制的数值映射
 * 5. 指针和内存地址映射
 * 6. 自定义格式化输出
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// 定义一个结构体用于演示复杂类型的输出映射
struct Person
{
    char name[30];
    int age;
    float height;
    bool isStudent;
};

int main()
{
    printf("=== C语言输出映射完整示例 ===\n\n");

    /* ===================== 1. 基本数据类型的格式映射 ===================== */
    printf("【1. 基本数据类型的格式映射】\n");

    // 整数映射
    int decimal = 42;
    unsigned int unsigned_num = 4294967295U;
    short short_num = -32768;
    long long long_long_num = 9223372036854775807LL;

    printf("十进制整数: %d\n", decimal);
    printf("无符号十进制: %u\n", unsigned_num);
    printf("短整型: %hd\n", short_num);
    printf("长长整型: %lld\n", long_long_num);

    // 浮点数映射
    float float_num = 3.14159265f;
    double double_num = 2.718281828459045;
    long double long_double_num = 1.6180339887498948482L;

    printf("单精度浮点: %f\n", float_num);
    printf("双精度浮点: %lf\n", double_num);
    printf("长双精度浮点: %Lf\n", long_double_num);

    // 字符和字符串映射
    char single_char = 'A';
    char string[] = "Hello, C!";
    char special_chars[] = "换行\n制表\t回车\r退格\b双引号\"";

    printf("单个字符: %c\n", single_char);
    printf("字符串: %s\n", string);
    printf("特殊字符序列: %s\n", special_chars);

    // 布尔值映射 (C99标准)
    bool is_true = true;
    bool is_false = false;

    printf("布尔值 true: %s (内部值: %d)\n", is_true ? "true" : "false", is_true);
    printf("布尔值 false: %s (内部值: %d)\n\n", is_false ? "true" : "false", is_false);

    /* ===================== 2. 数值进制映射 ===================== */
    printf("【2. 数值进制映射】\n");

    int number = 42;

    printf("十进制: %d\n", number);
    printf("八进制: %o\n", number);          // 无前缀
    printf("八进制(带前缀): %#o\n", number); // 带0前缀
    printf("十六进制(小写): %x\n", number);
    printf("十六进制(大写): %X\n", number);
    printf("十六进制(带前缀): %#x\n", number); // 带0x前缀
    printf("二进制(手动): ");
    // 手动实现二进制输出（C标准库不直接支持%b）
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (number >> i) & 1);
        if (i % 4 == 0)
            printf(" "); // 每4位加空格便于阅读
    }
    printf("\n\n");

    /* ===================== 3. 格式控制映射 ===================== */
    printf("【3. 格式控制映射】\n");

    // 宽度控制
    printf("宽度控制:\n");
    printf("默认: |%d|\n", 42);
    printf("最小宽度10: |%10d|\n", 42);         // 右对齐
    printf("最小宽度10,左对齐: |%-10d|\n", 42); // 左对齐
    printf("填充零: |%010d|\n", 42);            // 用0填充

    // 精度控制
    printf("\n精度控制:\n");
    printf("浮点数默认: %f\n", 3.14159265);
    printf("浮点数精度2: %.2f\n", 3.14159265);
    printf("浮点数宽度10精度2: |%10.2f|\n", 3.14159265);

    // 字符串截断
    char long_string[] = "This is a very long string for demonstration";
    printf("完整字符串: %s\n", long_string);
    printf("截取前10字符: %.10s\n", long_string);
    printf("宽度20截取10字符: |%20.10s|\n", long_string);

    // 符号控制
    int positive = 42;
    int negative = -42;

    printf("\n符号控制:\n");
    printf("默认正数: %d\n", positive);
    printf("默认负数: %d\n", negative);
    printf("强制显示符号: %+d\n", positive);
    printf("空格代替正号: % d\n", positive);
    printf("负数始终显示: %+d\n", negative);

    // 进制格式控制
    printf("\n进制格式控制:\n");
    printf("十六进制宽度8: |%8x|\n", 0x1a3f);
    printf("十六进制前导零: |%08x|\n", 0x1a3f);
    printf("十六进制前缀: |%#x|\n", 0x1a3f);
    printf("十六进制大写: |%X|\n", 0x1a3f);
    printf("十六进制大写前缀: |%#X|\n\n", 0x1a3f);

    /* ===================== 4. 指针和内存地址映射 ===================== */
    printf("【4. 指针和内存地址映射】\n");

    int value = 12345;
    int *ptr = &value;
    char *str_ptr = "Memory Address";

    printf("变量value的地址: %p\n", (void *)&value);
    printf("指针ptr的值(地址): %p\n", (void *)ptr);
    printf("指针ptr指向的值: %d\n", *ptr);
    printf("字符串字面量地址: %p\n", (void *)str_ptr);
    printf("字符串内容: %s\n", str_ptr);

    // 演示内存布局（字节级映射）
    printf("\n内存字节级映射 (int = %d):\n", value);
    unsigned char *bytes = (unsigned char *)&value;
    for (size_t i = 0; i < sizeof(int); i++)
    {
        printf("字节 %zu: 0x%02x (%3d)\n", i, bytes[i], bytes[i]);
    }
    printf("注意: 字节顺序取决于系统字节序(大端/小端)\n\n");

    /* ===================== 5. 特殊字符和转义序列映射 ===================== */
    printf("【5. 特殊字符和转义序列映射】\n");

    printf("换行符 \\n:\n这是新行\n");
    printf("制表符 \\t: 第一列\t第二列\t第三列\n");
    printf("回车符 \\r: 覆盖前面的内容\r这是新内容\n");
    printf("退格符 \\b: Hello\b\b\b\b\bWorld\n");
    printf("警报符 \\a: 会发出响铃声 (可能听不到)\a\n");
    printf("双引号 \\\": \"quoted text\"\n");
    printf("单引号 \\\': \'quoted text\'\n");
    printf("反斜杠 \\\\: C:\\Program Files\\App\n");
    printf("垂直制表 \\v:\n第一行\v第二行\v第三行\n");
    printf("换页符 \\f: (在打印机或某些终端中有特殊效果)\f\n\n");

    /* ===================== 6. 高级格式化映射 ===================== */
    printf("【6. 高级格式化映射】\n");

    // 科学计数法
    double large_num = 123456789.0;
    double small_num = 0.00000012345;

    printf("科学计数法(小写): %e\n", large_num);
    printf("科学计数法(大写): %E\n", small_num);
    printf("智能选择(小写): %g\n", large_num); // 自动选择%f或%e
    printf("智能选择(大写): %G\n", small_num);

    // 百分比和特殊字符
    printf("\n百分比符号: %%\n");
    printf("NUL字符: \\0 (不会显示在输出中)\0\n");

    // 动态格式控制
    int width = 15;
    int precision = 3;
    printf("\n动态宽度和精度:\n");
    printf("动态宽度%2d: |%*d|\n", width, width, 42);
    printf("动态精度%2d: |%.*f|\n", precision, precision, 3.14159265);

    /* ===================== 7. 结构体和复杂类型映射 ===================== */
    printf("【7. 结构体和复杂类型映射】\n");

    struct Person person = {"张三", 25, 175.5f, true};

    printf("结构体Person:\n");
    printf("  姓名: %-20s | 年龄: %3d 岁\n", person.name, person.age);
    printf("  身高: %6.1f cm       | 学生: %s\n",
           person.height, person.isStudent ? "是" : "否");

    // 复杂格式化表格
    printf("\n复杂表格输出:\n");
    printf("+%-20s+%-10s+%-10s+%-10s+\n", "-------------------", "----------", "----------", "----------");
    printf("| 姓名                | 年龄      | 身高(cm)  | 学生      |\n");
    printf("+%-20s+%-10s+%-10s+%-10s+\n", "-------------------", "----------", "----------", "----------");
    printf("| %-18s | %8d | %8.1f | %-8s |\n",
           person.name, person.age, person.height, person.isStudent ? "是" : "否");
    printf("+%-20s+%-10s+%-10s+%-10s+\n", "-------------------", "----------", "----------", "----------");

    /* ===================== 8. 时间和日期映射 ===================== */
    printf("【8. 时间和日期映射】\n");

    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);

    char time_str[80];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

    printf("当前时间(完整): %s\n", time_str);
    printf("年月日: %d年%02d月%02d日\n",
           time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday);
    printf("时分秒: %02d:%02d:%02d\n",
           time_info->tm_hour, time_info->tm_min, time_info->tm_sec);

    /* ===================== 9. 颜色输出映射 (ANSI转义序列) ===================== */
    printf("【9. 颜色输出映射 (ANSI转义序列)】\n");

    // 注意: 在Kali Linux终端中，这些颜色代码会生效
    printf("\033[31m这是红色文本\033[0m\n");
    printf("\033[32m这是绿色文本\033[0m\n");
    printf("\033[33m这是黄色文本\033[0m\n");
    printf("\033[34m这是蓝色文本\033[0m\n");
    printf("\033[35m这是紫色文本\033[0m\n");
    printf("\033[36m这是青色文本\033[0m\n");
    printf("\033[37m这是白色文本\033[0m\n");
    printf("\033[1;31m这是加粗红色文本\033[0m\n");
    printf("\033[4;32m这是下划线绿色文本\033[0m\n");
    printf("\033[44;37m这是蓝底白字\033[0m\n\n");

    /* ===================== 10. 完整示例：数据报表映射 ===================== */
    printf("【10. 完整示例：数据报表映射】\n");

    // 模拟学生成绩数据
    struct
    {
        char id[10];
        char name[20];
        float math;
        float english;
        float average;
    } students[] = {
        {"S001", "张三", 85.5, 92.0, 88.75},
        {"S002", "李四", 95.0, 88.5, 91.75},
        {"S003", "王五", 78.0, 85.5, 81.75},
        {"S004", "赵六", 92.5, 96.0, 94.25}};

    int student_count = sizeof(students) / sizeof(students[0]);

    // 打印表头
    printf("\n%6s %-15s %8s %8s %8s\n", "学号", "姓名", "数学", "英语", "平均分");
    printf("%6s %-15s %8s %8s %8s\n", "------", "---------------", "--------", "--------", "--------");

    // 打印数据行
    for (int i = 0; i < student_count; i++)
    {
        printf("%6s %-15s %8.1f %8.1f %8.2f\n",
               students[i].id,
               students[i].name,
               students[i].math,
               students[i].english,
               students[i].average);
    }

    // 打印统计信息
    float total_avg = 0.0f;
    for (int i = 0; i < student_count; i++)
    {
        total_avg += students[i].average;
    }
    total_avg /= student_count;

    printf("%6s %-15s %8s %8s %8.2f\n",
           "", "", "", "班级平均:", total_avg);

    printf("\n=== 程序结束 ===\n");
    return 0;
}

/**
 * 补充说明：输出映射的核心概念
 *
 * 1. 格式说明符映射规则：
 *    - %d/%i  -> 有符号整数
 *    - %u     -> 无符号整数
 *    - %f     -> 浮点数
 *    - %c     -> 单个字符
 *    - %s     -> 字符串
 *    - %p     -> 指针地址
 *    - %x/%X  -> 十六进制
 *    - %o     -> 八进制
 *    - %%     -> 百分号本身
 *
 * 2. 格式控制标志：
 *    - -      : 左对齐
 *    - +      : 显示符号（正数显示+，负数显示-）
 *    - (空格): 正数前加空格，负数显示-
 *    - #      : 显示进制前缀（0x, 0等）
 *    - 0      : 用0填充（而不是空格）
 *
 * 3. 字段宽度和精度：
 *    - %10d   : 最小宽度10，右对齐
 *    - %-10d  : 最小宽度10，左对齐
 *    - %.2f   : 保留2位小数
 *    - %10.2f : 宽度10，保留2位小数
 *
 * 4. 长度修饰符：
 *    - hh     : char类型（%hhd, %hhu）
 *    - h      : short类型（%hd, %hu）
 *    - l      : long类型（%ld, %lu）
 *    - ll     : long long类型（%lld, %llu）
 *    - L      : long double类型（%Lf）
 *
 * 5. 特殊字符映射：
 *    - \n     : 换行
 *    - \t     : 水平制表
 *    - \r     : 回车
 *    - \b     : 退格
 *    - \a     : 警报（响铃）
 *    - \\     : 反斜杠
 *    - \"     : 双引号
 *    - \'     : 单引号
 *
 * 6. ANSI颜色代码（在Linux终端有效）：
 *    - \033[31m : 红色前景
 *    - \033[32m : 绿色前景
 *    - \033[44m : 蓝色背景
 *    - \033[1m  : 加粗
 *    - \033[4m  : 下划线
 *    - \033[0m  : 重置所有属性
 */