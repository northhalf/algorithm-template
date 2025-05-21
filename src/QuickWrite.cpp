/* UTF-8 */
// 快速读取数字的算法模板
#include <cctype>
#include <iostream>
#include <limits>
#include <type_traits>

/**
 * @brief 快速输出整数
 * @param num 需要输出的整数
 */
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void QuickWrite(T num) {
    // 栈来存储数字的各位字符，先进后出
    static unsigned char stack[20];
    char top = 0;
    // 原类型的无符号类型
    using unsigned_T = std::make_unsigned_t<T>;
    unsigned_T abs;  // 存储原类型的无符号转换结果

    // 如果数字为负数则输出负号和符号反转
    if (num < 0) {
        std::putchar('-');
        // 将原来数字转化为绝对值
        if (num == std::numeric_limits<T>::min()) {
            // 如果这个数字是原来有符号数字最小值，那么其绝对值为最大值+1
            abs = static_cast<unsigned_T>(std::numeric_limits<T>::max()) + 1;
        } else {
            abs = static_cast<unsigned_T>(-num);
        }
    } else {  // 原来数字为正数的话直接转化为绝对值
        abs = static_cast<unsigned_T>(num);
    }

    // 往栈内放入数字字符
    do {
        stack[static_cast<size_t>(top++)] =
            static_cast<unsigned char>(abs % 10) + '0';
        abs /= 10;
    } while (abs != 0);
    // 不断弹出字符直到顶部索引为0
    while (top > 0) {
        std::putchar(stack[static_cast<int>(--top)]);
    }
    // 换行并刷新缓冲区
    std::putchar('\n');
}