// #Hard #Top_100_Liked_Questions #String #Dynamic_Programming #Stack #Big_O_Time_O(n)_Space_O(1)
// #2024_05_24_Time_0_ms_(100.00%)_Space_8_MB_(96.84%)

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(const string& s) {
        int maxLen = 0;
        int left = 0, right = 0;
        int n = s.length();

        // Left to right scan
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (right > left) {
                left = right = 0;
            }
            if (left == right) {
                maxLen = max(maxLen, left + right);
            }
        }

        left = right = 0;

        // Right to left scan
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left > right) {
                left = right = 0;
            }
            if (left == right) {
                maxLen = max(maxLen, left + right);
            }
        }

        return maxLen;
    }
};
