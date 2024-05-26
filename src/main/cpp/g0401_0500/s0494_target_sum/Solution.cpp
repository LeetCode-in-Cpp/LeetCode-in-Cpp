// #Medium #Array #Dynamic_Programming #Backtracking #Big_O_Time_O(n*(sum+s))_Space_O(n*(sum+s))
// #2024_05_22_Time_8_ms_(70.29%)_Space_15.8_MB_(37.03%)

#include <vector>
#include <cmath>>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = 0;
        s = abs(s);
        for (int num : nums) {
            sum += num;
        }
        // Invalid s, just return 0
        if (s > sum || (sum + s) % 2 != 0) {
            return 0;
        }
        int target = (sum + s) / 2;
        vector<vector<int>> dp(target + 1, vector<int>(nums.size() + 1, 0));
        dp[0][0] = 1;
        // empty knapsack must be processed specially
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                dp[0][i + 1] = dp[0][i] * 2;
            } else {
                dp[0][i + 1] = dp[0][i];
            }
        }
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                dp[i][j + 1] += dp[i][j];
                if (nums[j] <= i) {
                    dp[i][j + 1] += dp[i - nums[j]][j];
                }
            }
        }
        return dp[target][nums.size()];
    }
};
