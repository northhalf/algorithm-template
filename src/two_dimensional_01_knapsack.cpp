#include <algorithm>
#include <vector>
template <typename W, typename V>
int knapsack_01_two_dimension(
    W max_capability, std::vector<W> &wvec, std::vector<V> &vvex
) {
    W size = wvec.size();
    std::vector<std::vector<V>> dp(
        size + 1, std::vector<V>(max_capability + 1, 0)
    );
    for (W i = 1; i <= size; i++) {
        for (W j = 1; j <= max_capability; j++) {
            if (j >= wvec[i]) {
                dp[i][j] =
                    std::max(dp[i - 1][j - wvec[i]] + vvex[i], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[size][max_capability];
}