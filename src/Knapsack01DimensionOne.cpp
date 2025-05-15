/* UTF-8 */
// 01背包一维解法
#include <algorithm>
#include <utility>
#include <vector>

// W 为物品重量的数据类型，V 为物品价值的数据类型
template <typename W, typename V>
V Knapsack01DimensionOne(
    // 需要背包的最大容量，以及一个记录物品重量和价值的数组
    W max_capability, std::vector<std::pair<W, V>> items
) {
    // 记录物品的个数
    size_t size = items.size();
    std::vector<V> dp(max_capability + 1, 0);
    // 枚举物品
    for (size_t i = 1; i <= size; i++) {
        // 枚举背包可能容量
        for (W j = max_capability; j >= items[i].first; j--) {
            // 由选和不选第i的物品获得最大价值
            dp[j] = std::max(dp[j - items[i].first] + items[i].second, dp[j]);
        }
    }
    return dp[max_capability];
}
