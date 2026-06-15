/*
 * C语言全数据类型展示程序
 * 编译命令: gcc -std=c99 all_data_types.c -o all_data_types
 * 运行命令: ./all_data_types
 *
 * 本程序完整展示了C语言的所有基本数据类型，包括：
 * 1. 基本数据类型（整数、浮点、字符、布尔）
 * 2. 修饰符（signed, unsigned, short, long）
 * 3. 派生数据类型（指针、数组、结构体、联合体、枚举）
 * 4. void类型
 */

#include <stdio.h>   // 标准输入输出库，用于printf等函数
#include <stdbool.h> // C99标准布尔类型库
#include <string.h>  // 字符串处理库，用于strcpy等函数
#include <limits.h>  // 整数类型极限值库
#include <float.h>   // 浮点类型极限值库

// 定义枚举类型：星期几
enum Weekday
{
    MONDAY = 1, // 枚举常量，值为1
    TUESDAY,    // 自动递增，值为2
    WEDNESDAY,  // 值为3
    THURSDAY,   // 值为4
    FRIDAY,     // 值为5
    SATURDAY,   // 值为6
    SUNDAY      // 值为7
};

// 定义结构体类型：学生信息
struct Student
{
    int id;           // 学号
    char name[50];    // 姓名（字符数组）
    float gpa;        // 成绩（浮点数）
    bool isGraduated; // 是否毕业（布尔值）
};

// 定义联合体类型：不同类型的数据共享同一内存空间
union Data
{
    int integerValue; // 整数值
    float floatValue; // 浮点值
    char charValue;   // 字符值
    bool boolValue;   // 布尔值
};

// 函数声明：展示void类型函数
void showVoidExample(void);

int main()
{
    printf("=== C语言全数据类型展示程序 ===\n\n");

    /* ===================== 1. 基本整数类型 ===================== */
    printf("【1. 基本整数类型】\n");

    // char类型：通常用于表示字符，但本质是小整数
    char myChar = 'A'; // 字符'A'的ASCII码是65
    printf("char: '%c' (ASCII: %d), 大小: %zu 字节\n",
           myChar, (int)myChar, sizeof(char));

    // signed char：有符号字符类型，范围-128到127
    signed char signedChar = -128;
    printf("signed char: %d, 大小: %zu 字节\n", signedChar, sizeof(signed char));

    // unsigned char：无符号字符类型，范围0到255
    unsigned char unsignedChar = 255;
    printf("unsigned char: %u, 大小: %zu 字节\n\n", unsignedChar, sizeof(unsigned char));

    /* ===================== 2. 短整型 ===================== */
    printf("【2. 短整型 (short)】\n");

    // short int：短整型，通常2字节
    short int shortInt = -32768; // short的最小值
    /*short shortInt = -32768; // short的最小值*/
    printf("short int: %d, 大小: %zu 字节, 范围: %d 到 %d\n",
           shortInt, sizeof(short int), SHRT_MIN, SHRT_MAX);

    // unsigned short int：无符号短整型
    unsigned short int unsignedShort = 65535; // unsigned short的最大值
    printf("unsigned short int: %u, 大小: %zu 字节, 范围: 0 到 %u\n\n",
           unsignedShort, sizeof(unsigned short int), USHRT_MAX);

    /* ===================== 3. 整型 (int) ===================== */
    printf("【3. 整型 (int)】\n");

    // int：标准整型，通常4字节（取决于编译器和系统）
    int myInt = 2147483647; // 32位系统int的最大值
    printf("int: %d, 大小: %zu 字节, 范围: %d 到 %d\n",
           myInt, sizeof(int), INT_MIN, INT_MAX);

    // unsigned int：无符号整型
    unsigned int unsignedInt = 4294967295U; // 32位系统unsigned int的最大值
    printf("unsigned int: %u, 大小: %zu 字节, 范围: 0 到 %u\n\n",
           unsignedInt, sizeof(unsigned int), UINT_MAX);

    /* ===================== 4. 长整型 (long) ===================== */
    printf("【4. 长整型 (long)】\n");

    // long int：长整型，通常4或8字节
    long int longInt = 2147483647L; // 32位系统long的最大值
    printf("long int: %ld, 大小: %zu 字节, 范围: %ld 到 %ld\n",
           longInt, sizeof(long int), LONG_MIN, LONG_MAX);

    // unsigned long int：无符号长整型
    unsigned long int unsignedLong = 4294967295UL;
    printf("unsigned long int: %lu, 大小: %zu 字节, 范围: 0 到 %lu\n\n",
           unsignedLong, sizeof(unsigned long int), ULONG_MAX);

    /* ===================== 5. 长长整型 (long long) ===================== */
    printf("【5. 长长整型 (long long) - C99标准】\n");

    // long long int：长长整型，通常8字节
    long long int longLongInt = 9223372036854775807LL; // 64位最大值
    printf("long long int: %lld, 大小: %zu 字节, 范围: %lld 到 %lld\n",
           longLongInt, sizeof(long long int), LLONG_MIN, LLONG_MAX);

    // unsigned long long int：无符号长长整型
    unsigned long long int unsignedLongLong = 18446744073709551615ULL;
    printf("unsigned long long int: %llu, 大小: %zu 字节, 范围: 0 到 %llu\n\n",
           unsignedLongLong, sizeof(unsigned long long int), ULLONG_MAX);

    /* ===================== 6. 浮点类型 ===================== */
    printf("【6. 浮点类型】\n");

    // float：单精度浮点数，通常4字节
    float myFloat = 3.1415926535f;
    printf("float: %.10f, 大小: %zu 字节, 精度: %d 位\n",
           myFloat, sizeof(float), FLT_DIG);

    // double：双精度浮点数，通常8字节
    double myDouble = 3.14159265358979323846;
    printf("double: %.15f, 大小: %zu 字节, 精度: %d 位\n",
           myDouble, sizeof(double), DBL_DIG);

    // long double：扩展精度浮点数，通常10或16字节
    long double myLongDouble = 3.1415926535897932384626433832795L;
    printf("long double: %.20Lf, 大小: %zu 字节, 精度: %d 位\n\n",
           myLongDouble, sizeof(long double), LDBL_DIG);

    /* ===================== 7. 布尔类型 (C99标准) ===================== */
    printf("【7. 布尔类型 (bool) - C99标准】\n");

    bool isTrue = true;   // true = 1
    bool isFalse = false; // false = 0

    printf("bool true: %d (值为true)\n", isTrue);
    printf("bool false: %d (值为false)\n", isFalse);
    printf("bool 大小: %zu 字节\n\n", sizeof(bool));

    /* ===================== 8. 指针类型 ===================== */
    printf("【8. 指针类型】\n");

    int value = 42;
    int *intPointer = &value; // 指向int的指针

    printf("普通变量 value: %d, 地址: %p\n", value, (void *)&value);
    printf("指针变量 intPointer: %p, 指向的值: %d\n",
           (void *)intPointer, *intPointer);
    printf("指针大小: %zu 字节\n\n", sizeof(intPointer));

    /* ===================== 9. 枚举类型 ===================== */
    printf("【9. 枚举类型 (enum)】\n");

    enum Weekday today = WEDNESDAY;

    printf("枚举变量 today: %d (%s)\n", today,
           (today == MONDAY) ? "星期一" : (today == TUESDAY) ? "星期二"
                                      : (today == WEDNESDAY) ? "星期三"
                                      : (today == THURSDAY)  ? "星期四"
                                      : (today == FRIDAY)    ? "星期五"
                                      : (today == SATURDAY)  ? "星期六"
                                                             : "星期日");
    printf("枚举大小: %zu 字节\n\n", sizeof(enum Weekday));

    /* ===================== 10. 结构体类型 ===================== */
    printf("【10. 结构体类型 (struct)】\n");

    struct Student student1;
    student1.id = 1001;
    /* 使用strncpy以避免对snprintf/strcpy的隐式声明问题，同时保证以\0结尾 */
    strncpy(student1.name, "张三", sizeof(student1.name) - 1);
    student1.name[sizeof(student1.name) - 1] = '\0';
    student1.gpa = 3.8f;
    student1.isGraduated = false;

    printf("结构体 student1:\n");
    printf("  学号: %d\n", student1.id);
    printf("  姓名: %s\n", student1.name);
    printf("  GPA: %.1f\n", student1.gpa);
    printf("  是否毕业: %s\n", student1.isGraduated ? "是" : "否");
    printf("结构体大小: %zu 字节\n\n", sizeof(struct Student));

    /* ===================== 11. 联合体类型 ===================== */
    printf("【11. 联合体类型 (union)】\n");

    union Data myData;

    // 联合体在同一时间只能存储一个成员的值
    myData.integerValue = 65;
    printf("联合体存储整数: %d\n", myData.integerValue);

    myData.floatValue = 3.14f;
    printf("联合体存储浮点数: %.2f\n", myData.floatValue);

    myData.charValue = 'A';
    printf("联合体存储字符: '%c'\n", myData.charValue);

    myData.boolValue = true;
    printf("联合体存储布尔值: %s\n", myData.boolValue ? "true" : "false");
    printf("联合体大小: %zu 字节 (取最大成员的大小)\n\n", sizeof(union Data));

    /* ===================== 12. void类型 ===================== */
    printf("【12. void类型】\n");
    showVoidExample(); // 调用void函数

    /* ===================== 13. 数组类型 ===================== */
    printf("【13. 数组类型】\n");

    int numbers[5] = {1, 2, 3, 4, 5}; // 整型数组
    char message[20] = "Hello, C!";   // 字符数组（字符串）

    printf("整型数组 numbers: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("字符数组 message: %s\n", message);
    printf("整型数组大小: %zu 字节\n", sizeof(numbers));
    printf("字符数组大小: %zu 字节\n\n", sizeof(message));

    printf("=== 程序结束 ===\n");
    return 0; // 0表示程序成功执行
}

/**
 * void类型函数示例
 * void表示函数不返回任何值
 * void作为参数列表表示函数不接受任何参数
 */
void showVoidExample(void)
{
    printf("void函数示例: 这个函数不返回任何值，也不接受参数\n");

    // void指针示例：可以指向任何类型的数据
    int intValue = 100;
    void *voidPointer = &intValue;

    // 使用void指针时需要强制类型转换
    printf("void指针示例: intValue = %d, 通过void指针访问: %d\n",
           intValue, *((int *)voidPointer));
}

/**
 * 补充说明：
 *
 * 1. 数据类型大小说明：
 *    - sizeof()运算符返回类型或变量在内存中占用的字节数
 *    - 不同系统/编译器下，某些类型的大小可能不同（特别是int、long等）
 *
 * 2. 修饰符说明：
 *    - signed：有符号（默认），可表示正负数
 *    - unsigned：无符号，只能表示非负数，范围翻倍
 *    - short：短整型，占用空间小于int
 *    - long：长整型，占用空间大于或等于int
 *    - long long：长长整型，占用空间最大
 *
 * 3. 格式说明符：
 *    - %d/%i：有符号整数
 *    - %u：无符号整数
 *    - %c：字符
 *    - %s：字符串
 *    - %f：浮点数
 *    - %lf：双精度浮点数
 *    - %Lf：长双精度浮点数
 *    - %p：指针地址
 *    - %zu：size_t类型（用于sizeof结果）
 *
 * 4. C99标准新增：
 *    - bool类型（需要#include <stdbool.h>）
 *    - //单行注释
 *    - 变量可以在代码块的任意位置声明
 *
 * 5. 编译建议：
 *    使用gcc -std=c99参数启用C99标准支持
 */