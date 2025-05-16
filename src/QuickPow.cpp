#include <stdexcept>
#include <type_traits>

template <
    typename T1, typename T2,
    typename = typename std::enable_if_t<std::is_integral_v<T2>>>
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