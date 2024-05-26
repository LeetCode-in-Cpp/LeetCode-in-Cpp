// #Medium #Top_100_Liked_Questions #String #Dynamic_Programming
// #Algorithm_II_Day_18_Dynamic_Programming #Dynamic_Programming_I_Day_19
// #Udemy_Dynamic_Programming #Big_O_Time_O(n^2)_Space_O(n2)
// #2024_05_26_Time_0_ms_(100.00%)_Space_8.7_MB_(99.94%)

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minDistance(const std::string& w1, const std::string& w2) {
        int n1 = w1.length();
        int n2 = w2.length();
        if (n2 > n1) {
            return minDistance(w2, w1);
        }
        std::vector<int> dp(n2 + 1);
        for (int j = 0; j <= n2; j++) {
            dp[j] = j;
        }
        for (int i = 1; i <= n1; i++) {
            int pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n2; j++) {
                int tmp = dp[j];
                dp[j] = (w1[i - 1] != w2[j - 1])
                        ? 1 + std::min(pre, std::min(dp[j], dp[j - 1]))
                        : pre;
                pre = tmp;
            }
        }
        return dp[n2];
    }
};
