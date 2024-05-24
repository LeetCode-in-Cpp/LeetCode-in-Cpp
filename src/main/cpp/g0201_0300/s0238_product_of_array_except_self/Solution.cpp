// #Medium #Top_100_Liked_Questions #Array #Prefix_Sum #Data_Structure_II_Day_5_Array #Udemy_Arrays
// #Big_O_Time_O(n^2)_Space_O(n) #2024_05_24_Time_21_ms_(88.52%)_Space_38_MB_(86.36%)

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int product = 1;
        std::vector<int> ans(nums.size(), 1);

        for (int num : nums) {
            product *= num;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                ans[i] = product / nums[i];
            } else {
                int p = 1;
                for (int j = 0; j < nums.size(); j++) {
                    if (j != i) {
                        p *= nums[j];
                    }
                }
                ans[i] = p;
            }
        }

        return ans;
    }
};
