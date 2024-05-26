// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Bit_Manipulation #Backtracking
// #Algorithm_II_Day_9_Recursion_Backtracking #Udemy_Backtracking/Recursion
// #Big_O_Time_O(2^n)_Space_O(n*2^n) #2024_05_26_Time_0_ms_(100.00%)_Space_8.1_MB_(99.14%)

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> temp;
        solve(nums, temp, res, 0);
        return res;
    }

private:
    void solve(const std::vector<int>& nums, std::vector<int>& temp, std::vector<std::vector<int>>& res, int start) {
        res.push_back(temp);
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            solve(nums, temp, res, i + 1);
            temp.pop_back();
        }
    }
};
