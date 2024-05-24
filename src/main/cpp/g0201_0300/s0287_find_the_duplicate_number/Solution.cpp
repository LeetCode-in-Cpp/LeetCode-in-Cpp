// #Medium #Top_100_Liked_Questions #Array #Binary_Search #Two_Pointers #Bit_Manipulation
// #Binary_Search_II_Day_5 #Big_O_Time_O(n)_Space_O(n)
// #2024_05_24_Time_74_ms_(75.71%)_Space_66.1_MB_(19.28%)

#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::vector<int> arr(nums.size() + 1, 0);
        for (int num : nums) {
            arr[num] += 1;
            if (arr[num] == 2) {
                return num;
            }
        }
        return 0;
    }
};
