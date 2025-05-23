/* UTF-8 */
// 快速幂算法模板
#include <concepts>
#include <my_concepts.hpp>
#include <stdexcept>

/*
 @brief 计算一个数的n次幂运算结果
 @param base: 底数(需要为算术类型)
 @param exponent: 指数(需要为自然数)
 @return 运算结果，类型与第一个参数相同
 **/
template <myconcept::Arithmetic T1, std::integral T2>
T1 QuickPow(T1 base, T2 exponent) {
    // 处理指数为0的情况
    if (exponent == 0) {
        // 不允许0^0的情况
        if (base == 0) {
            throw std::invalid_argument("Error: The 0th power of 0 is undefined"
            );
        }
        // 底数不为0，则返回1
        return static_cast<T1>(1);
    }
    // 要求指数为非负数
    if (exponent < 0)
        throw std::out_of_range("Error: the exponent must be natural number");

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