// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Dynamic_Programming #Math
// #Combinatorics #Algorithm_II_Day_13_Dynamic_Programming #Dynamic_Programming_I_Day_15
// #Level_1_Day_11_Dynamic_Programming #Big_O_Time_O(m*n)_Space_O(m*n)
// #2024_05_25_Time_0_ms_(100.00%)_Space_7.7_MB_(44.80%)

#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        
        // Initialize the first column to 1
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        
        // Initialize the first row to 1
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        
        // Fill the rest of the dp array
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
