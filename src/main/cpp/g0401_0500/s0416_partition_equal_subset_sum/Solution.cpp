// #Medium #Top_100_Liked_Questions #Array #Dynamic_Programming #Level_2_Day_13_Dynamic_Programming
// #Big_O_Time_O(n*sums)_Space_O(n*sums) #2024_05_22_Time_199_ms_(41.03%)_Space_12.3_MB_(92.82%)

#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sums = 0;
        for (int num : nums) {
            sums += num;
        }
        if (sums % 2 == 1) {
            return false;
        }
        sums /= 2;
        vector<bool> dp(sums + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int sum = sums; sum >= num; --sum) {
                dp[sum] = dp[sum] || dp[sum - num];
            }
        }
        return dp[sums];
    }
};
