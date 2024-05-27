// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table #Union_Find
// #Big_O_Time_O(N_log_N)_Space_O(1) #2024_05_27_Time_63_ms_(92.78%)_Space_49.3_MB_(84.61%)

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        std::sort(nums.begin(), nums.end());
        int maxLen = 1;
        int currentLen = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                ++currentLen;
            } else if (nums[i] != nums[i - 1]) {
                maxLen = std::max(maxLen, currentLen);
                currentLen = 1;
            }
        }

        return std::max(maxLen, currentLen);
    }
};
