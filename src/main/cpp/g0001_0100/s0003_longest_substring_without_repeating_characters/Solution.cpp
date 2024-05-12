// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Hash_Table #Sliding_Window
// #Algorithm_I_Day_6_Sliding_Window #Level_2_Day_14_Sliding_Window/Two_Pointer #Udemy_Strings
// #Big_O_Time_O(n)_Space_O(1) #2024_05_12_Time_5_ms_(86.87%)_Space_10.4_MB_(74.49%)

#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> lastIndices(256, -1);
        int maxLen = 0;
        int curLen = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            char cur = s[i];
            if (lastIndices[cur] < start) {
                lastIndices[cur] = i;
                curLen++;
            } else {
                int lastIndex = lastIndices[cur];
                start = lastIndex + 1;
                curLen = i - start + 1;
                lastIndices[cur] = i;
            }
            maxLen = std::max(maxLen, curLen);
        }
        return maxLen;
    }
};
