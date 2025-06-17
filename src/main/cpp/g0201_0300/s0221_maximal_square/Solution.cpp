// #Medium #Array #Dynamic_Programming #Matrix #Dynamic_Programming_I_Day_16
// #Top_Interview_150_Multidimensional_DP #Big_O_Time_O(m*n)_Space_O(m*n)
// #2024_05_26_Time_56_ms_(84.56%)_Space_24.5_MB_(55.52%)

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    // 1 + minimum from cell above, cell to the left, cell diagonal upper-left
                    int next = 1 + std::min(dp[i][j], std::min(dp[i + 1][j], dp[i][j + 1]));
                    // keep track of the maximum value seen
                    if (next > max) {
                        max = next;
                    }
                    dp[i + 1][j + 1] = next;
                }
            }
        }
        return max * max;
    }
};
