/* UTF-8 */
// 快速幂算法模板
#include <concepts>
#include <stdexcept>

/*
 @brief 计算一个数的n次幂运算结果
 @param base: 底数
 @param exponent: 指数
 @return 运算结果
 **/
template <typename T1, std::integral T2>
T1 QuickPow(T1 base, T2 exponent) {
    // 要求指数为正整数
    if (exponent <= 0)
        throw std::out_of_range("Error: the exponent must be positive");
    T1 res = 1;  // 记录结果
    // 快速幂
    while (exponent > 0) {
        if (exponent & 1) {
            res *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    return res;
}