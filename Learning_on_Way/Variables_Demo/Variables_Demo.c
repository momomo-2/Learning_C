/*
 * ============================================================
 *  C语言 —— 变量完全指南
 *  编译环境：Kali Linux (GCC)
 *  编译命令：gcc variables_demo.c -o variables_demo
 *  运行命令：./variables_demo
 * ============================================================
 */

#include <stdio.h>  /* 标准输入输出库，提供 printf、scanf 等函数 */
#include <limits.h> /* 提供各整数类型的最大/最小值宏，如 INT_MAX */
#include <float.h>  /* 提供各浮点类型的精度信息宏，如 FLT_MAX */
#include <string.h> /* 提供字符串处理函数，如 strlen */

/* ============================================================
 * 【知识点 1】全局变量 与 宏常量（定义在函数外部）
 * ============================================================
 * - 全局变量：定义在所有函数之外，整个程序都可访问
 * - 宏常量：用 #define 定义，编译前会被文本替换，不占内存
 */

/* 全局变量 —— 不初始化时自动为 0（整数）或 0.0（浮点数） */
int g_score = 100;     /* 全局整型变量，前缀 g_ 是常见的命名习惯 */
double g_pi = 3.14159; /* 全局双精度浮点变量 */

/* 宏常量 —— 用 #define 定义，值不可修改 */
#define MAX_STUDENTS 50               /* 编译时所有 MAX_STUDENTS 会被替换为 50 */
#define SCHOOL_NAME "Kali University" /* 字符串宏常量 */

/* 函数声明（前置声明，让 main 函数能调用后面定义的函数） */
void section_basic_types(void);
void section_naming_rules(void);
void section_initialization(void);
void section_format_specifiers(void);
void section_type_limits(void);
void section_unsigned_types(void);
void section_type_conversion(void);
void section_const_variables(void);
void section_scope_demo(void);
void section_static_demo(void);
void section_sizeof_demo(void);
void section_overflow_demo(void);
void section_input_demo(void);
void local_vs_global_demo(void);

/* ============================================================
 *  main 函数 —— 程序入口
 * ============================================================ */
int main(void)
{
    printf("╔══════════════════════════════════════════╗\n");
    printf("║     C语言 —— 变量完全指南 (详细注释版)    ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    /* 依次演示各个知识点 */
    section_basic_types();       /* 第1节：基本数据类型 */
    section_naming_rules();      /* 第2节：变量命名规则 */
    section_initialization();    /* 第3节：声明与初始化 */
    section_format_specifiers(); /* 第4节：格式化输出 */
    section_type_limits();       /* 第5节：类型范围与极限 */
    section_unsigned_types();    /* 第6节：无符号类型 */
    section_type_conversion();   /* 第7节：类型转换 */
    section_const_variables();   /* 第8节：常量与 const */
    section_scope_demo();        /* 第9节：变量作用域 */
    section_static_demo();       /* 第10节：static 静态变量 */
    section_sizeof_demo();       /* 第11节：sizeof 运算符 */
    section_overflow_demo();     /* 第12节：溢出演示 */
    section_input_demo();        /* 第13节：用户输入 */
    local_vs_global_demo();      /* 第14节：全局 vs 局部 */

    printf("\n════════════════════════════════════════════\n");
    printf("  🎉 恭喜！所有变量知识点演示完毕！\n");
    printf("════════════════════════════════════════════\n");

    return 0; /* 返回 0 表示程序正常结束 */
}

/* ============================================================
 *  第1节：基本数据类型
 * ============================================================
 *  C语言的变量必须先「声明类型」再使用。
 *  基本类型分为四大类：
 *    ① 整型 (int)     —— 存储整数
 *    ② 浮点型 (float, double) —— 存储小数
 *    ③ 字符型 (char)  —— 存储单个字符
 *    ④ 字符串（char 数组）—— 存储一串字符（C语言没有 string 类型！）
 */
void section_basic_types(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第1节：基本数据类型\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    /* ---- ① 整型 ---- */
    /* int：普通整数，通常占 4 字节，范围约 -21亿 ~ +21亿 */
    int age = 20;
    printf("[int]   age = %d\n", age);

    /* short：短整数，占 2 字节，范围 -32768 ~ 32767 */
    short temperature = -15;
    printf("[short] temperature = %hd\n", temperature);

    /* long：长整数，至少 4 字节（64位Linux上通常为 8 字节） */
    long population = 7800000000L; /* 注意末尾的 L 表示 long 常量 */
    printf("[long]  population = %ld\n", population);

    /* long long：超长整数，占 8 字节，范围约 ±9.2×10^18 */
    long long distance = 9876543210123LL; /* 末尾 LL 表示 long long */
    printf("[long long] distance = %lld\n", distance);

    /* ---- ② 浮点型 ---- */
    /* float：单精度浮点，占 4 字节，约 6~7 位有效数字 */
    float price = 19.99f;                     /* 末尾的 f 表示 float 常量（否则默认是 double） */
    printf("[float]  price = %.2f\n", price); /* %.2f 表示保留2位小数 */

    /* double：双精度浮点，占 8 字节，约 15~16 位有效数字 */
    double precise_pi = 3.141592653589793;
    printf("[double] precise_pi = %.15f\n", precise_pi);

    /* ---- ③ 字符型 ---- */
    /* char：单个字符，占 1 字节，用单引号包裹 */
    char grade = 'A';
    printf("[char]   grade = '%c'\n", grade);

    /* char 本质上是小整数（ASCII 码值），'A' 的 ASCII 值是 65 */
    printf("[char→int] grade 的 ASCII 码 = %d\n", grade);

    /* ---- ④ 字符串（char 数组） ---- */
    /* C语言没有内置 string 类型，用 char 数组 + '\0' 结尾表示字符串 */
    char name[] = "Kali Linux";               /* 编译器自动添加 '\0' 结尾 */
    printf("[string] name = \"%s\"\n", name); /* %s 输出字符串 */
    printf("[string] name 占 %lu 字节（含 '\\0'）\n", sizeof(name));

    printf("\n");
}

/* ============================================================
 *  第2节：变量命名规则
 * ============================================================
 *  合法命名规则：
 *    ① 只能包含 字母、数字、下划线（_）
 *    ② 不能以数字开头
 *    ③ 不能是C语言关键字（如 int, return, if, while 等）
 *    ④ 区分大小写（age 和 Age 是两个不同的变量）
 *
 *  推荐命名风格：
 *    - 驼峰命名：myVariableName（C语言较少用）
 *    - 蛇形命名：my_variable_name（C语言最常用 ✅）
 *    - 见名知意：用有意义的英文单词命名
 */
void section_naming_rules(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第2节：变量命名规则\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    /* ✅ 合法的变量名 */
    int my_age = 20;       /* 蛇形命名，推荐！ */
    int studentCount = 30; /* 驼峰命名，也可以 */
    int _private_var = 99; /* 下划线开头，合法但不推荐 */
    int x = 1;             /* 单字母，合法但仅适合循环计数器 */
    int counter2 = 0;      /* 数字不在开头，合法 */

    printf("✅ 合法命名示例：\n");
    printf("   my_age = %d\n", my_age);
    printf("   studentCount = %d\n", studentCount);
    printf("   _private_var = %d\n", _private_var);
    printf("   x = %d\n", x);
    printf("   counter2 = %d\n", counter2);

    /* ❌ 以下命名都是非法的（已注释，取消注释会导致编译错误）：*/
    /* int 2nd_place = 1;   */ /* ❌ 数字开头 */
    /* int my-name   = 1;   */ /* ❌ 包含连字符（减号） */
    /* int int       = 1;   */ /* ❌ 使用了关键字 */
    /* int my name   = 1;   */ /* ❌ 包含空格 */

    printf("\n   ❌ 非法命名（编译会报错）：\n");
    printf("      2nd_place  → 数字开头\n");
    printf("      my-name    → 包含连字符\n");
    printf("      int        → 使用了关键字\n");
    printf("      my name    → 包含空格\n");

    printf("\n");
}

/* ============================================================
 *  第3节：声明与初始化的各种方式
 * ============================================================ */
void section_initialization(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第3节：声明与初始化\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    /* 方式1：先声明，后赋值 */
    int a;
    a = 10;
    printf("方式1（先声明后赋值）: a = %d\n", a);

    /* 方式2：声明时直接初始化（推荐 ✅） */
    int b = 20;
    printf("方式2（声明时初始化）: b = %d\n", b);

    /* 方式3：同时声明多个同类型变量 */
    int x = 1, y = 2, z = 3;
    printf("方式3（批量声明）: x=%d, y=%d, z=%d\n", x, y, z);

    /* 方式4：使用表达式初始化 */
    int sum = a + b;
    printf("方式4（表达式初始化）: sum = a + b = %d\n", sum);

    /* 方式5：C99 指定初始化（用于数组和结构体） */
    int arr[5] = {[0] = 10, [2] = 30, [4] = 50}; /* 其余元素自动为 0 */
    printf("方式5（指定初始化）: arr = [%d, %d, %d, %d, %d]\n",
           arr[0], arr[1], arr[2], arr[3], arr[4]);

    /* ⚠️ 未初始化的局部变量值是「不确定的」（垃圾值） */
    int danger; /* 没有赋初值！ */
    printf("⚠️  未初始化变量: danger = %d （值不确定，切勿依赖！）\n", danger);

    printf("\n");
}

/* ============================================================
 *  第4节：格式化输出（printf 的格式说明符）
 * ============================================================
 *  每种数据类型对应不同的格式说明符：
 *    %d / %i  → int（有符号十进制整数）
 *    %hd      → short
 *    %ld      → long
 *    %lld     → long long
 *    %u       → unsigned int
 *    %f       → float / double（默认6位小数）
 *    %e       → 科学计数法
 *    %c       → char（单个字符）
 *    %s       → 字符串（char*）
 *    %x / %X  → 十六进制（小写/大写）
 *    %o       → 八进制
 *    %p       → 指针地址
 *    %%       → 输出百分号本身
 */
void section_format_specifiers(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第4节：格式化输出（格式说明符大全）\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    int num = 255;
    double decimal = 3.14159;
    char ch = 'K';
    char str[] = "Hello";

    printf("整数输出：\n");
    printf("  %%d  → %d\n", num); /* 十进制: 255 */
    printf("  %%x  → %x\n", num); /* 十六进制小写: ff */
    printf("  %%X  → %X\n", num); /* 十六进制大写: FF */
    printf("  %%o  → %o\n", num); /* 八进制: 377 */

    printf("\n浮点数输出：\n");
    printf("  %%f   → %f\n", decimal);    /* 默认6位小数: 3.141590 */
    printf("  %%.2f  → %.2f\n", decimal); /* 保留2位小数: 3.14 */
    printf("  %%.4f  → %.4f\n", decimal); /* 保留4位小数: 3.1416（四舍五入） */
    printf("  %%e   → %e\n", decimal);    /* 科学计数法: 3.141590e+00 */

    printf("\n宽度与对齐：\n");
    printf("  |%%10d|    → |%10d|    （右对齐，占10位）\n", num);
    printf("  |%%-10d|   → |%-10d|   （左对齐，占10位）\n", num);
    printf("  |%%05d|    → |%05d|    （前补零，占5位）\n", num);

    printf("\n字符与字符串：\n");
    printf("  %%c  → %c\n", ch);  /* 字符: K */
    printf("  %%s  → %s\n", str); /* 字符串: Hello */
    printf("  %%10s → %10s  （右对齐）\n", str);

    printf("\n百分号本身：100%%%% = 100%%\n");

    printf("\n");
}

/* ============================================================
 *  第5节：类型范围与极限值
 * ============================================================
 *  <limits.h> 和 <float.h> 提供了各类型的边界值
 */
void section_type_limits(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第5节：类型范围与极限值\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    printf("整数类型范围（来自 <limits.h>）：\n");
    printf("  char       : %d ~ %d\n", CHAR_MIN, CHAR_MAX);
    printf("  short      : %hd ~ %hd\n", SHRT_MIN, SHRT_MAX);
    printf("  int        : %d ~ %d\n", INT_MIN, INT_MAX);
    printf("  long       : %ld ~ %ld\n", LONG_MIN, LONG_MAX);
    printf("  long long  : %lld ~ %lld\n", LLONG_MIN, LLONG_MAX);

    printf("\n浮点类型信息（来自 <float.h>）：\n");
    printf("  float  最大值 : %e\n", FLT_MAX);
    printf("  float  最小正值: %e\n", FLT_MIN);
    printf("  float  有效位数: %d 位\n", FLT_DIG);
    printf("  double 最大值 : %e\n", DBL_MAX);
    printf("  double 最小正值: %e\n", DBL_MIN);
    printf("  double 有效位数: %d 位\n", DBL_DIG);

    printf("\n");
}

/* ============================================================
 *  第6节：无符号类型（unsigned）
 * ============================================================
 *  - unsigned 类型只能表示 ≥0 的非负数
 *  - 同样占 4 字节，但 unsigned int 范围是 0 ~ 约42亿
 *  - 适用场景：数组索引、位操作、计数器等不会出现负数的场景
 */
void section_unsigned_types(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第6节：无符号类型（unsigned）\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    int signed_val = -100;            /* 有符号：可为负 */
    unsigned int unsigned_val = 100u; /* 无符号：只能非负，末尾 u */

    printf("有符号 int:   %d\n", signed_val);
    printf("无符号 int:   %u\n", unsigned_val); /* %u 用于无符号 */

    /* 无符号类型的范围更大（正数方向） */
    printf("\n范围对比：\n");
    printf("  int          : %d ~ %d\n", INT_MIN, INT_MAX);
    printf("  unsigned int : 0 ~ %u\n", UINT_MAX);

    /* ⚠️ 无符号类型减去大数会「环绕」（wrap around） */
    unsigned int zero = 0;
    unsigned int wrapped = zero - 1; /* 0 - 1 变成最大值！ */
    printf("\n⚠️  unsigned 环绕示例：\n");
    printf("  0u - 1 = %u （不是 -1，而是最大值！）\n", wrapped);

    printf("\n");
}

/* ============================================================
 *  第7节：类型转换
 * ============================================================
 *  ① 隐式转换（自动转换）：小类型 → 大类型，编译器自动完成
 *     char → short → int → long → float → double
 *  ② 显式转换（强制转换）：用 (类型) 语法，可能导致精度丢失
 */
void section_type_conversion(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第7节：类型转换\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    /* ---- 隐式转换（自动提升） ---- */
    printf("【隐式转换（自动）】\n");

    int i_val = 10;
    double d_val = 3.5;

    /* int 自动转换为 double 再运算 */
    double result1 = i_val + d_val; /* 10 → 10.0, 然后 10.0 + 3.5 */
    printf("  int(10) + double(3.5) = %.1f （int自动提升为double）\n", result1);

    /* char 自动提升为 int */
    char c = 'A';         /* ASCII = 65 */
    int c_as_int = c + 1; /* 'A' → 65, 65 + 1 = 66 */
    printf("  'A' + 1 = %d （char自动提升为int）\n", c_as_int);

    /* ---- 显式转换（强制类型转换） ---- */
    printf("\n【显式转换（强制）】\n");

    double pi = 3.99;
    int truncated = (int)pi; /* 强制转换：直接截断小数部分，不四舍五入 */
    printf("  (int)3.99 = %d （截断小数，不是四舍五入！）\n", truncated);

    int total = 7, count = 2;
    /* 整数除法 7/2 = 3（截断），需要先转换为 double */
    printf("  7 / 2 = %d （整数除法，结果截断）\n", total / count);
    printf("  (double)7 / 2 = %.1f （转换后得到精确结果）\n",
           (double)total / count);

    /* ⚠️ 大类型 → 小类型可能丢失数据 */
    printf("\n⚠️  【危险：精度丢失】\n");
    double big_double = 123456789.123456;
    int small_int = (int)big_double;
    float small_float = (float)big_double;
    printf("  double: %.6f\n", big_double);
    printf("  → int:  %d （小数丢失！）\n", small_int);
    printf("  → float: %.1f （精度不够！）\n", small_float);

    printf("\n");
}

/* ============================================================
 *  第8节：常量与 const 关键字
 * ============================================================
 *  定义常量的两种方式：
 *    ① #define 宏常量 —— 预处理阶段文本替换，无类型检查
 *    ② const 常量     —— 编译阶段有类型检查，更安全（推荐 ✅）
 */
void section_const_variables(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第8节：常量与 const\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    /* 方式1：#define 宏常量（已在文件顶部定义） */
    printf("#define 宏常量：\n");
    printf("  MAX_STUDENTS = %d\n", MAX_STUDENTS);
    printf("  SCHOOL_NAME  = \"%s\"\n", SCHOOL_NAME);

    /* 方式2：const 常量（有类型，推荐） */
    const double SPEED_OF_LIGHT = 299792458.0; /* m/s */
    const int DAYS_IN_WEEK = 7;
    const char NEWLINE = '\n';

    printf("\nconst 常量：\n");
    printf("  SPEED_OF_LIGHT = %.0f m/s\n", SPEED_OF_LIGHT);
    printf("  DAYS_IN_WEEK   = %d\n", DAYS_IN_WEEK);

    /* ❌ 试图修改 const 变量会导致编译错误 */
    /* DAYS_IN_WEEK = 8; */ /* 编译报错：assignment of read-only variable */
    printf("\n  ⚠️  const 变量不可修改（取消注释 DAYS_IN_WEEK = 8 会编译报错）\n");

    /* 两种方式对比 */
    printf("\n  对比：\n");
    printf("  #define → 预处理替换，无类型，调试困难\n");
    printf("  const   → 有类型检查，更安全，调试友好 ✅\n");

    printf("\n");
}

/* ============================================================
 *  第9节：变量作用域（Scope）
 * ============================================================
 *  作用域决定了变量在哪些地方可以被访问：
 *    ① 块作用域（局部变量）：定义在 {} 内，只在 {} 内有效
 *    ② 函数作用域：函数参数只在函数内有效
 *    ③ 文件作用域（全局变量）：定义在函数外，整个文件有效
 */

/* 辅助函数：演示局部作用域 */
void scope_helper(void)
{
    int local_var = 999; /* 这个变量只在 scope_helper 函数内有效 */
    printf("    在 scope_helper 内: local_var = %d\n", local_var);
    /* printf("%d", main_var); */ /* ❌ 无法访问 main 里的局部变量 */
}

void section_scope_demo(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第9节：变量作用域\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    int outer = 10; /* 外层块的变量 */
    printf("外层块: outer = %d\n", outer);

    {                   /* 开始一个新的代码块 */
        int inner = 20; /* 内层块的变量，只在此 {} 内有效 */
        printf("内层块: outer = %d, inner = %d\n", outer, inner);
        /* 内层块可以访问外层变量 outer */

        { /* 再嵌套一层 */
            int deep = 30;
            printf("深层块: outer=%d, inner=%d, deep=%d\n", outer, inner, deep);
        }
        /* printf("%d", deep); */ /* ❌ deep 已超出作用域，编译报错 */
    }
    /* printf("%d", inner); */ /* ❌ inner 已超出作用域，编译报错 */
    printf("回到外层: outer = %d （inner 和 deep 已不可访问）\n", outer);

    /* 调用辅助函数 */
    printf("\n调用 scope_helper()：\n");
    scope_helper();
    /* printf("%d", local_var); */ /* ❌ 无法访问其他函数的局部变量 */
    printf("  ⚠️  scope_helper 的 local_var 在此处不可访问\n");

    printf("\n");
}

/* ============================================================
 *  第10节：static 静态变量
 * ============================================================
 *  static 修饰局部变量时：
 *    - 变量只初始化一次
 *    - 函数结束后变量不会被销毁，值会保留
 *    - 但作用域仍然只在函数内部
 *
 *  static 修饰全局变量/函数时：
 *    - 限制其只在当前源文件中可见（内部链接）
 */

/* 辅助函数：演示 static 的效果 */
void static_counter(void)
{
    /* 普通局部变量：每次调用都重新初始化 */
    int normal_count = 0;

    /* 静态局部变量：只初始化一次，值在调用之间保留 */
    static int static_count = 0;

    normal_count++;
    static_count++;

    printf("    普通变量 = %d, 静态变量 = %d\n", normal_count, static_count);
}

void section_static_demo(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第10节：static 静态变量\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    printf("连续调用 static_counter() 三次：\n");
    static_counter(); /* 第1次调用 */
    static_counter(); /* 第2次调用 */
    static_counter(); /* 第3次调用 */

    printf("\n  解读：\n");
    printf("    普通变量每次都从 0 开始 → 始终为 1\n");
    printf("    静态变量保留上次的值   → 1, 2, 3 递增\n");

    printf("\n");
}

/* ============================================================
 *  第11节：sizeof 运算符
 * ============================================================
 *  sizeof 返回变量或类型占用的字节数
 *  注意：返回值类型是 size_t（无符号长整型），用 %%lu 输出
 */
void section_sizeof_demo(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第11节：sizeof 运算符（各类型占用字节数）\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    printf("基本类型的 sizeof：\n");
    printf("  sizeof(char)       = %lu 字节\n", sizeof(char)); /* 始终为 1 */
    printf("  sizeof(short)      = %lu 字节\n", sizeof(short));
    printf("  sizeof(int)        = %lu 字节\n", sizeof(int));
    printf("  sizeof(long)       = %lu 字节\n", sizeof(long));
    printf("  sizeof(long long)  = %lu 字节\n", sizeof(long long));
    printf("  sizeof(float)      = %lu 字节\n", sizeof(float));
    printf("  sizeof(double)     = %lu 字节\n", sizeof(double));

    /* sizeof 也可以用于变量名 */
    int my_var = 42;
    double my_arr[10];
    printf("\n对变量使用 sizeof：\n");
    printf("  sizeof(my_var)     = %lu 字节\n", sizeof(my_var));
    printf("  sizeof(my_arr)     = %lu 字节（10个double = 10×8）\n", sizeof(my_arr));
    printf("  数组元素个数       = %lu\n", sizeof(my_arr) / sizeof(my_arr[0]));

    printf("\n");
}

/* ============================================================
 *  第12节：溢出演示
 * ============================================================
 *  当变量的值超出其类型范围时，会发生「溢出」
 *  - 有符号整数溢出：未定义行为（Undefined Behavior）⚠️
 *  - 无符号整数溢出：有定义的环绕行为（wrap around）
 */
void section_overflow_demo(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第12节：溢出演示\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    /* short 的范围是 -32768 ~ 32767 */
    short max_short = 32767;
    printf("short 最大值: %hd\n", max_short);

    /* ⚠️ 有符号溢出是「未定义行为」，结果不可预测 */
    /* 大多数机器上会发生环绕，但这不是标准保证的 */
    short overflowed = max_short + 1;
    printf("short 最大值 + 1 = %hd （溢出！结果不可预测）\n", overflowed);

    /* 无符号溢出是「有定义的环绕」 */
    unsigned char max_uchar = 255; /* unsigned char 范围: 0~255 */
    unsigned char wrapped_uchar = max_uchar + 1;
    printf("\nunsigned char 最大值: %hhu\n", max_uchar);
    printf("unsigned char 最大值 + 1 = %hhu （有定义地环绕回 0）\n", wrapped_uchar);

    /* 浮点数溢出 → 变成 inf（无穷大） */
    float huge = 3.4e38f;
    printf("\nfloat 接近最大值: %e\n", huge);
    printf("float 溢出: %e → inf（无穷大）\n", huge * 10.0f);

    printf("\n");
}

/* ============================================================
 *  第13节：用户输入（scanf）
 * ============================================================
 *  scanf 从键盘读取输入并存入变量
 *  ⚠️  注意：scanf 需要传入变量的「地址」（用 & 取地址运算符）
 */
void section_input_demo(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第13节：用户输入（scanf）\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    int user_age;
    float user_height;
    char user_name[50]; /* 预留 50 字节存储名字 */

    printf("📝 请输入你的年龄（整数）：");
    scanf("%d", &user_age); /* %d 读取整数，& 取地址 */

    printf("📝 请输入你的身高（米，如 1.75）：");
    scanf("%f", &user_height); /* %f 读取 float */

    printf("📝 请输入你的名字（不含空格）：");
    scanf("%49s", user_name); /* %s 读取字符串，数组名本身就是地址，不加 & */
                              /* %49s 限制最多读49字符，防止缓冲区溢出 */

    printf("\n📋 你输入的信息：\n");
    printf("  姓名: %s\n", user_name);
    printf("  年龄: %d 岁\n", user_age);
    printf("  身高: %.2f 米\n", user_height);

    /* 清空输入缓冲区，防止残留的换行符影响后续输入 */
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("\n");
}

/* ============================================================
 *  第14节：全局变量 vs 局部变量
 * ============================================================ */
void local_vs_global_demo(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  第14节：全局变量 vs 局部变量\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    /* 访问全局变量（文件顶部定义的 g_score 和 g_pi） */
    printf("全局变量 g_score = %d\n", g_score);
    printf("全局变量 g_pi    = %.5f\n", g_pi);

    /* 局部变量可以「遮蔽」同名全局变量 */
    int g_score = 999; /* 这是局部变量，遮蔽了全局的 g_score */
    printf("局部变量 g_score = %d （遮蔽了全局变量）\n", g_score);

    /* 修改全局变量 */
    g_score = 200; /* 这里修改的是局部变量！ */
    printf("修改后 局部 g_score = %d\n", g_score);

    /* 总结对比表 */
    printf("\n  ┌────────────┬──────────────────┬──────────────────┐\n");
    printf("  │   特性      │    全局变量       │    局部变量       │\n");
    printf("  ├────────────┼──────────────────┼──────────────────┤\n");
    printf("  │ 定义位置    │ 函数外部          │ 函数/代码块内部   │\n");
    printf("  │ 生命周期    │ 整个程序运行期间   │ 离开作用域即销毁  │\n");
    printf("  │ 默认初值    │ 自动为 0          │ 不确定（垃圾值）  │\n");
    printf("  │ 作用域      │ 整个文件          │ 所在 {} 内       │\n");
    printf("  │ 存储位置    │ 数据段（BSS/Data） │ 栈（Stack）      │\n");
    printf("  └────────────┴──────────────────┴──────────────────┘\n");

    printf("\n");
}