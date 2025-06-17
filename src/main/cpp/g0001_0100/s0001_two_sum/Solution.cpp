// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table
// #Data_Structure_I_Day_2_Array #Level_1_Day_13_Hashmap #Udemy_Arrays #Top_Interview_150_Hashmap
// #Big_O_Time_O(n)_Space_O(n) #AI_can_be_used_to_solve_the_task
// #2024_05_12_Time_4_ms_(94.42%)_Space_14.1_MB_(17.14%)

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::unordered_map<int, int> indexMap;
        for (int i = 0; i < numbers.size(); i++) {
            int requiredNum = target - numbers[i];
            if (indexMap.find(requiredNum) != indexMap.end()) {
                return {indexMap[requiredNum], i};
            }
            indexMap[numbers[i]] = i;
        }
        return {-1, -1};
    }
};
