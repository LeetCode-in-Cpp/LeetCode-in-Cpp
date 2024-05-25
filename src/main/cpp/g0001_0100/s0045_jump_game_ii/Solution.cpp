// #Medium #Top_100_Liked_Questions #Array #Dynamic_Programming #Greedy
// #Algorithm_II_Day_13_Dynamic_Programming #Dynamic_Programming_I_Day_4
// #Big_O_Time_O(n)_Space_O(1) #2024_05_25_Time_8_ms_(82.92%)_Space_18.9_MB_(87.16%)

#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int length = 0;
        int maxLength = 0;
        int minJump = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            length--;
            maxLength--;
            maxLength = std::max(maxLength, nums[i]);
            if (length <= 0) {
                length = maxLength;
                minJump++;
            }
            if (length >= nums.size() - i - 1) {
                return minJump;
            }
        }
        return minJump;
    }
};
