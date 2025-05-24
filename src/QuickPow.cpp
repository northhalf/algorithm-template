/* UTF-8 */
// 快速幂算法模板
#include <concepts>
#include <my_concepts.hpp>
#include <stdexcept>
#include <type_traits>

/**
 * @brief 对QuickPow()函数中传入的参数(底数为整型)进行特判
 * @details
 * 对底数为整数类型时进行0,1,-1特判
 * @note 仅用于底数为整型的特判
 * @param base: 底数
 * @param exponent: 指数
 * @return 根据特判结果返回0,1,-1。2说明不是0 or 1 or -1
 * @throw std::invalid_argument 如果出现0^0的情况
 */
template <myconcept::Arithmetic T1, std::integral T2>
T1 __QuickPow_SpecialHandling(T1 base, T2 exponent) {
    // 处理底数为0的情况
    if (base == static_cast<T1>(0)) {
        // 不允许0^0的情况
        if (exponent == static_cast<T1>(0)) {
            throw std::invalid_argument("Error: The 0th power of 0 is undefined"
            );
        } else {  // 0^非零数字 = 0
            return static_cast<T1>(0);
        }
    }

    // 处理底数为1的特殊情况
    if (base == static_cast<T1>(1)) {
        return static_cast<T1>(1);
    }

    // 处理底数为-1的特殊情况
    if (std::is_signed_v<T1> and base == static_cast<T1>(-1)) {
        // 看指数是否为偶数
        return (exponent & 1) ? (static_cast<T1>(-1)) : (static_cast<T1>(1));
    }
    // 如果底数不是这三种情况
    return static_cast<T1>(2);
}

/*
 @brief 计算一个数的n次幂运算结果
 @warning 仅用于一般的自然数幂次计算
 @param base: 底数(需要为算术类型)
 @param exponent: 指数(需要为自然数)
 @return 运算结果，类型与第一个参数相同
 @throw std::invalid_argument 如果出现0^0的情况
 @throw std::out_of_range 如果一般底数的指数为负数
 **/
template <myconcept::Arithmetic T1, std::integral T2>
T1 QuickPow(T1 base, T2 exponent) {
    // 对于底数为整型可以对01情况进行特判
    if (std::is_integral_v<T1>) {
        T1 ans = __QuickPow_SpecialHandling(base, exponent);
        // 如果特判返回有效值则将其返回
        if (ans != 2) return ans;
    }

    // 一般情况下要求指数为非负数
    if (exponent < 0)
        throw std::out_of_range(
            "Error: the exponent must be natural number(if the base is not 1 "
            "or -1)"
        );

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