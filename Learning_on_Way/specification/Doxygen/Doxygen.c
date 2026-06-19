/**
 * @file student_manager.c
 * @brief 学生信息管理系统示例程序
 * @details 本程序演示了如何使用Doxygen风格的注释规范，
 *          包含结构体定义、函数声明和完整的注释标注。
 * @author 张三
 * @version 1.0
 * @date 2026-06-19
 * @copyright Copyright (c) 2026
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @def MAX_NAME_LENGTH
 * @brief 定义学生姓名的最大长度
 */
#define MAX_NAME_LENGTH 50

/**
 * @def MAX_STUDENTS
 * @brief 定义系统中可存储的最大学生数量
 */
#define MAX_STUDENTS 100

/**
 * @struct Student
 * @brief 学生信息结构体
 * @details 用于存储单个学生的基本信息，包括学号、姓名、年龄和成绩
 */
typedef struct
{
    int id;                     ///< 学生学号，唯一标识
    char name[MAX_NAME_LENGTH]; ///< 学生姓名
    int age;                    ///< 学生年龄，范围：16-100
    float score;                ///< 学生成绩，范围：0.0-100.0
} Student;

/**
 * @brief 初始化学生信息
 * @details 为指定的学生结构体设置初始值，包括学号、姓名、年龄和成绩
 *
 * @param[out] student 指向要初始化的学生结构体的指针
 * @param[in] id 学生学号
 * @param[in] name 学生姓名（字符串）
 * @param[in] age 学生年龄
 * @param[in] score 学生成绩
 *
 * @return 初始化成功返回 true，失败返回 false
 *
 * @note 姓名长度不能超过 MAX_NAME_LENGTH
 * @warning 请确保传入的指针不为 NULL
 *
 * @code
 * Student s;
 * init_student(&s, 1001, "李四", 20, 85.5);
 * @endcode
 */
bool init_student(Student *student, int id, const char *name, int age, float score)
{
    if (student == NULL || name == NULL)
    {
        return false;
    }

    student->id = id;
    strncpy(student->name, name, MAX_NAME_LENGTH - 1);
    student->name[MAX_NAME_LENGTH - 1] = '\0';
    student->age = age;
    student->score = score;

    return true;
}

/**
 * @brief 打印学生信息
 * @details 将学生的完整信息输出到标准输出
 *
 * @param[in] student 指向要打印的学生结构体的指针（只读）
 *
 * @return 无返回值
 *
 * @see init_student
 */
void print_student(const Student *student)
{
    if (student == NULL)
    {
        printf("错误：学生指针为空\n");
        return;
    }

    printf("学号: %d\n", student->id);
    printf("姓名: %s\n", student->name);
    printf("年龄: %d\n", student->age);
    printf("成绩: %.2f\n", student->score);
}

/**
 * @brief 计算学生成绩等级
 * @details 根据学生成绩返回对应的等级字符
 *          - 90-100: 'A'
 *          - 80-89: 'B'
 *          - 70-79: 'C'
 *          - 60-69: 'D'
 *          - 0-59: 'F'
 *
 * @param[in] score 学生成绩
 *
 * @retval 'A' 成绩优秀（90-100分）
 * @retval 'B' 成绩良好（80-89分）
 * @retval 'C' 成绩中等（70-79分）
 * @retval 'D' 成绩及格（60-69分）
 * @retval 'F' 成绩不及格（0-59分）
 */
char get_grade(float score)
{
    if (score >= 90.0)
        return 'A';
    if (score >= 80.0)
        return 'B';
    if (score >= 70.0)
        return 'C';
    if (score >= 60.0)
        return 'D';
    return 'F';
}

/**
 * @brief 程序主入口函数
 * @details 演示学生信息管理的基本操作流程
 *
 * @param argc 命令行参数个数
 * @param argv 命令行参数数组
 *
 * @return 程序执行成功返回 0，失败返回非零值
 */
int main(int argc, char *argv[])
{
    Student stu1;

    // 初始化学生信息
    if (!init_student(&stu1, 1001, "张三", 20, 88.5))
    {
        printf("初始化失败\n");
        return 1;
    }

    // 打印学生信息
    printf("=== 学生信息 ===\n");
    print_student(&stu1);

    // 获取并打印成绩等级
    char grade = get_grade(stu1.score);
    printf("成绩等级: %c\n", grade);

    return 0;
}