// #Medium #Top_100_Liked_Questions #String #Dynamic_Programming #LeetCode_75_DP/Multidimensional
// #Algorithm_II_Day_17_Dynamic_Programming #Dynamic_Programming_I_Day_19
// #Udemy_Dynamic_Programming #Big_O_Time_O(n*m)_Space_O(n*m)
// #2024_05_21_Time_23_ms_(62.70%)_Space_25.6_MB_(50.39%)

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
        int n = text1.size();
        int m = text2.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};
