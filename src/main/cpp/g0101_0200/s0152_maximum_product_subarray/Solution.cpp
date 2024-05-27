// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming
// #Dynamic_Programming_I_Day_6 #Level_2_Day_13_Dynamic_Programming #Udemy_Dynamic_Programming
// #Big_O_Time_O(N)_Space_O(1) #2024_05_27_Time_3_ms_(85.90%)_Space_16.2_MB_(45.89%)

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int ans = INT_MIN;
        int cprod = 1;
        for (int j : nums) {
            cprod *= j;
            ans = std::max(ans, cprod);
            if (cprod == 0) {
                cprod = 1;
            }
        }
        cprod = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            cprod *= nums[i];
            ans = std::max(ans, cprod);
            if (cprod == 0) {
                cprod = 1;
            }
        }
        return ans;
    }
};
