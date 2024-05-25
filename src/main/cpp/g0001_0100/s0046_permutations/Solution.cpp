// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Backtracking
// #Algorithm_I_Day_11_Recursion_Backtracking #Level_2_Day_20_Brute_Force/Backtracking
// #Udemy_Backtracking/Recursion #Big_O_Time_O(n*n!)_Space_O(n+n!)
// #2024_05_25_Time_0_ms_(100.00%)_Space_9.6_MB_(50.28%)

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        std::vector<std::vector<int>> finalResult;
        std::vector<int> currResult;
        std::vector<bool> used(nums.size(), false);
        permuteRecur(nums, finalResult, currResult, used);
        return finalResult;
    }

private:
    void permuteRecur(const std::vector<int>& nums, 
                      std::vector<std::vector<int>>& finalResult, 
                      std::vector<int>& currResult, 
                      std::vector<bool>& used) {
        if (currResult.size() == nums.size()) {
            finalResult.push_back(currResult);
            return;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            currResult.push_back(nums[i]);
            used[i] = true;
            permuteRecur(nums, finalResult, currResult, used);
            used[i] = false;
            currResult.pop_back();
        }
    }
};
