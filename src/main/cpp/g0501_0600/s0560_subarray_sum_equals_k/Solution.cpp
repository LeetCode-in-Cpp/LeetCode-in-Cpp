// #Medium #Top_100_Liked_Questions #Array #Hash_Table #Prefix_Sum #Data_Structure_II_Day_5_Array
// #Big_O_Time_O(n)_Space_O(n) #2024_05_21_Time_54_ms_(92.60%)_Space_45_MB_(70.78%)

#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int tempSum = 0;
        int ret = 0;
        std::unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        
        for (int num : nums) {
            tempSum += num;
            if (sumCount.find(tempSum - k) != sumCount.end()) {
                ret += sumCount[tempSum - k];
            }
            if (sumCount.find(tempSum) != sumCount.end()) {
                sumCount[tempSum]++;
            } else {
                sumCount[tempSum] = 1;
            }
        }
        return ret;
    }
};
