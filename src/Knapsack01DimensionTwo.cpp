/* UTF-8 */
// 01背包二维解法
#include <algorithm>
#include <utility>
#include <vector>

// W 为物品重量的数据类型，V 为物品价值的数据类型
template <typename W, typename V>
V Knapsack01DimensionTwo(
    // 需要背包的最大容量，以及一个记录物品重量和价值的数组
    W max_capability, std::vector<std::pair<W, V>> items
) {
    // 记录物品的个数
    size_t size = items.size();
    std::vector<std::vector<V>> dp(
        size + 1, std::vector<V>(max_capability + 1, 0)
    );
    // 枚举物品
    for (size_t i = 1; i <= size; i++) {
        // 枚举背包容量
        for (W j = 1; j <= max_capability; j++) {
            if (j >= items[i].first) {
                // 如果背包容量能装下这个物品
                // 取装和不装的最大值
                dp[i][j] = std::max(
                    dp[i - 1][j - items[i].first] + items[i].second,
                    dp[i - 1][j]
                );
            } else {
                // 背包容量装不下这个物品
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[size][max_capability];
}