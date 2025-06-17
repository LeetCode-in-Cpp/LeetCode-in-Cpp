// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming
// #LeetCode_75_DP/1D #Algorithm_I_Day_12_Dynamic_Programming #Dynamic_Programming_I_Day_3
// #Level_2_Day_12_Dynamic_Programming #Udemy_Dynamic_Programming #Top_Interview_150_1D_DP
// #Big_O_Time_O(n)_Space_O(n) #2024_05_26_Time_2_ms_(40.41%)_Space_9.2_MB_(58.86%)

#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        }
        
        std::vector<int> profit(nums.size());
        profit[0] = nums[0];
        profit[1] = std::max(nums[0], nums[1]);
        
        for (size_t i = 2; i < nums.size(); ++i) {
            profit[i] = std::max(profit[i - 1], nums[i] + profit[i - 2]);
        }
        
        return profit.back();
    }
};
