/* UTF-8 */
// 快速读取数字的算法模板
#include <cctype>
#include <iostream>
#include <type_traits>

/**
 * @brief 快速输出整数
 */
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void QuickWrite(T num) {
    // 栈来存储数字的各位字符，先进后出
    static unsigned char stack[20];
    char top = 0;

    // 如果数字为负数则输出负号和符号反转
    if (num < 0) {
        std::putchar('-');
        num = -num;
    }
    // 往栈内放入数字字符
    do {
        stack[static_cast<int>(top++)] =
            static_cast<unsigned char>(num % 10) + '0';
        num /= 10;
    } while (num > 0);
    // 不断弹出字符直到顶部索引为0
    while (top > 0) {
        std::putchar(stack[static_cast<int>(--top)]);
    }
    // 换行并刷新缓冲区
    std::putchar('\n');
}