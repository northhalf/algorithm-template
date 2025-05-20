/* UTF-8 */
// 快速读取数字的算法模板
#include <cctype>
#include <iostream>
#include <type_traits>

/**
 * @brief 快速读取输入的整数
 * @return 读取到的数字
 */
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
T QuickRead() {
    bool minus = false;  // 记录该数字是否为负数
    T res = 0;
    // 获取第一个字符
    unsigned char ch = std::getchar();
    // 直到读取到数字字符
    while (!isdigit(ch)) {
        // 如果字符为负号则标注负数
        if (ch == '-') minus = true;
        ch = std::getchar();
    }
    // 读取数字字符
    while (isdigit(ch)) {
        res = res * 10 + (ch - '0');  // 不断累加
        ch = std::getchar();
    }

    // 根据负数标记决定返回负号
    return minus ? (-res) : res;
}