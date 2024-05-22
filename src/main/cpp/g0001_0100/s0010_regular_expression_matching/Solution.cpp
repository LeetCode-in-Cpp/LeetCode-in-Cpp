// #Hard #Top_Interview_Questions #String #Dynamic_Programming #Recursion #Udemy_Dynamic_Programming
// #Big_O_Time_O(m*n)_Space_O(m*n) #2024_05_22_Time_0_ms_(100.00%)_Space_8.2_MB_(63.58%)

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::optional<bool>>> cache;

    bool isMatch(const std::string& s, const std::string& p) {
        cache.resize(s.length() + 1, std::vector<std::optional<bool>>(p.length() + 1));
        return isMatchHelper(s, p, 0, 0);
    }

private:
    bool isMatchHelper(const std::string& s, const std::string& p, int i, int j) {
        if (j == p.length()) {
            return i == s.length();
        }

        if (cache[i][j].has_value()) {
            return cache[i][j].value();
        }

        bool firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        bool result;
        if ((j + 1) < p.length() && p[j + 1] == '*') {
            result = (firstMatch && isMatchHelper(s, p, i + 1, j)) || isMatchHelper(s, p, i, j + 2);
        } else {
            result = firstMatch && isMatchHelper(s, p, i + 1, j + 1);
        }

        cache[i][j] = result;
        return result;
    }
};
