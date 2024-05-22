// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Dynamic_Programming
// #Data_Structure_II_Day_9_String #Algorithm_II_Day_14_Dynamic_Programming
// #Dynamic_Programming_I_Day_17 #Udemy_Strings #Big_O_Time_O(n)_Space_O(n)
// #2024_05_22_Time_7_ms_(94.72%)_Space_9.2_MB_(70.29%)

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(const std::string& s) {
        // Transform s into newStr with delimiters
        std::string newStr(s.length() * 2 + 1, '#');
        for (int i = 0; i < s.length(); ++i) {
            newStr[2 * i + 1] = s[i];
        }

        std::vector<int> dp(newStr.length(), 0);
        int friendCenter = 0, friendRadius = 0;
        int lpsCenter = 0, lpsRadius = 0;

        for (int i = 0; i < newStr.length(); ++i) {
            dp[i] = (friendCenter + friendRadius > i)
                    ? std::min(dp[2 * friendCenter - i], friendCenter + friendRadius - i)
                    : 1;
            
            while (i + dp[i] < newStr.length() && i - dp[i] >= 0 && newStr[i + dp[i]] == newStr[i - dp[i]]) {
                dp[i]++;
            }
            
            if (friendCenter + friendRadius < i + dp[i]) {
                friendCenter = i;
                friendRadius = dp[i];
            }

            if (lpsRadius < dp[i]) {
                lpsCenter = i;
                lpsRadius = dp[i];
            }
        }

        int start = (lpsCenter - lpsRadius + 1) / 2;
        int length = lpsRadius - 1;
        return s.substr(start, length);
    }
};
