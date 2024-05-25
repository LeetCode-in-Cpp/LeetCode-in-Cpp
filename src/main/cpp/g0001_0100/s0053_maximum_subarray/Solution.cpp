// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming
// #Divide_and_Conquer #Data_Structure_I_Day_1_Array #Dynamic_Programming_I_Day_5
// #Udemy_Famous_Algorithm #Big_O_Time_O(n)_Space_O(1)
// #2024_05_25_Time_65_ms_(93.14%)_Space_70.2_MB_(66.74%)

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for (const int& num : nums) {
            sum += num;
            maxi = std::max(sum, maxi);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};
