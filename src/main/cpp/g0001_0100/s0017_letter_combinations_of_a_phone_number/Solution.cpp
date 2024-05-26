// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Hash_Table #Backtracking
// #Algorithm_II_Day_11_Recursion_Backtracking #Udemy_Backtracking/Recursion
// #Big_O_Time_O(4^n)_Space_O(n) #2024_05_23_Time_0_ms_(100.00%)_Space_7.8_MB_(91.42%)

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string curr;
        findCombinations(0, digits, letters, curr, ans);
        return ans;
    }

private:
    void findCombinations(int start, const string& nums, const vector<string>& letters, string& curr, vector<string>& ans) {
        if (curr.length() == nums.length()) {
            ans.push_back(curr);
            return;
        }

        int n = nums[start] - '0';
        for (char ch : letters[n]) {
            curr.push_back(ch);
            findCombinations(start + 1, nums, letters, curr, ans);
            curr.pop_back();
        }
    }
};
