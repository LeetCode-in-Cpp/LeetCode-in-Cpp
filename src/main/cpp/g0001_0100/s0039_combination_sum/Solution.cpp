// #Medium #Top_100_Liked_Questions #Array #Backtracking #Algorithm_II_Day_10_Recursion_Backtracking
// #Level_2_Day_20_Brute_Force/Backtracking #Udemy_Backtracking/Recursion
// #Big_O_Time_O(2^n)_Space_O(n+2^n) #2024_05_24_Time_0_ms_(100.00%)_Space_12.2_MB_(97.15%)

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& coins, int amount) {
        vector<vector<int>> ans;
        vector<int> subList;
        combinationSumRec(coins.size(), coins, amount, subList, ans);
        return ans;
    }

private:
    void combinationSumRec(int n, vector<int>& coins, int amount, vector<int>& subList, vector<vector<int>>& ans) {
        if (amount == 0 || n == 0) {
            if (amount == 0) {
                ans.push_back(subList);
            }
            return;
        }
        if (amount - coins[n - 1] >= 0) {
            subList.push_back(coins[n - 1]);
            combinationSumRec(n, coins, amount - coins[n - 1], subList, ans);
            subList.pop_back();
        }
        combinationSumRec(n - 1, coins, amount, subList, ans);
    }
};
