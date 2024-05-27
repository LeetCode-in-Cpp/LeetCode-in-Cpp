// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Dynamic_Programming
// #Backtracking #Big_O_Time_O(N*2^N)_Space_O(2^N*N)
// #2024_05_27_Time_69_ms_(83.20%)_Space_52.8_MB_(63.51%)

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> currArr;
        backtracking(res, currArr, s, 0);
        return res;
    }

private:
    void backtracking(std::vector<std::vector<std::string>>& res, std::vector<std::string>& currArr, const std::string& s, int start) {
        if (start == s.length()) {
            res.push_back(currArr);
        }
        for (int end = start; end < s.length(); end++) {
            if (!isPalindrome(s, start, end)) {
                continue;
            }
            currArr.push_back(s.substr(start, end - start + 1));
            backtracking(res, currArr, s, end + 1);
            currArr.pop_back();
        }
    }

    bool isPalindrome(const std::string& s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            start++;
            end--;
        }
        return start >= end;
    }
};
