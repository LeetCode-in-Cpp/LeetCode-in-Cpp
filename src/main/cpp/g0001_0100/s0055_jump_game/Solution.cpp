// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming #Greedy
// #Algorithm_II_Day_12_Dynamic_Programming #Dynamic_Programming_I_Day_4 #Udemy_Arrays
// #Big_O_Time_O(n)_Space_O(1) #2024_05_25_Time_31_ms_(96.95%)_Space_50.8_MB_(80.64%)

#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int sz = nums.size();
        int tmp = 1;
        for (int i = 0; i < sz; ++i) {
            tmp--;
            if (tmp < 0) {
                return false;
            }
            tmp = std::max(tmp, nums[i]);
            if (i + tmp >= sz - 1) {
                return true;
            }
        }
        return true;
    }
};
