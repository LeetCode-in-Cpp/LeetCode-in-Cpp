// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Array #Bit_Manipulation
// #LeetCode_75_Bit_Manipulation #Data_Structure_II_Day_1_Array
// #Algorithm_I_Day_14_Bit_Manipulation #Udemy_Integers #Top_Interview_150_Bit_Manipulation
// #Big_O_Time_O(N)_Space_O(1) #2024_05_27_Time_11_ms_(82.25%)_Space_19.1_MB_(84.99%)

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }
};
