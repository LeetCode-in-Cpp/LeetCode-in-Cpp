// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Dynamic_Programming
// #Backtracking #Algorithm_II_Day_11_Recursion_Backtracking #Udemy_Backtracking/Recursion
// #Big_O_Time_O(2^n)_Space_O(n) #2024_05_23_Time_0_ms_(100.00%)_Space_11.7_MB_(85.25%)

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        generate(current, ans, n, n);
        return ans;
    }

private:
    void generate(string& current, vector<string>& ans, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(current);
            return;
        }
        if (open > 0) {
            current.push_back('(');
            generate(current, ans, open - 1, close);
            current.pop_back();
        }
        if (close > 0 && open < close) {
            current.push_back(')');
            generate(current, ans, open, close - 1);
            current.pop_back();
        }
    }
};
