// #Medium #Top_100_Liked_Questions #Array #Dynamic_Programming #Breadth_First_Search
// #Algorithm_II_Day_18_Dynamic_Programming #Dynamic_Programming_I_Day_20
// #Level_2_Day_12_Dynamic_Programming #Top_Interview_150_1D_DP #Big_O_Time_O(m*n)_Space_O(amount)
// #2024_05_22_Time_12_ms_(97.65%)_Space_16_MB_(67.57%)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                int prev = dp[i - coin];
                if (prev > 0) {
                    if (dp[i] == 0) {
                        dp[i] = prev + 1;
                    } else {
                        dp[i] = min(dp[i], prev + 1);
                    }
                }
            }
        }
        return dp[amount] - 1;
    }
};
