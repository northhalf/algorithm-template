/* UTF-8 */
// 欧拉筛模板
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <vector>
/*
 @brief 计算自然数中不超过n的素数个数
 @param n: 素数最大范围
 @return 包含素数数组和素数标记的元组
 **/
template <std::integral T>
std::tuple<std::vector<T>, std::vector<bool>> EulerSieve(T n) {
    // n 必须为自然数
    if (n < 0) throw std::out_of_range("Error: n must be a natural number");
    std::vector<bool> is_prime(n, true);
    std::vector<T> primes;
    for (T i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);

        for (T j = 0; j < static_cast<T>(primes.size()) && i * primes[j] <= n;
             j++) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }
    return {primes, is_prime};
}