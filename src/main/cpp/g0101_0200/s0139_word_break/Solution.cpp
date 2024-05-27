// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Hash_Table
// #Dynamic_Programming #Trie #Memoization #Algorithm_II_Day_15_Dynamic_Programming
// #Dynamic_Programming_I_Day_9 #Udemy_Dynamic_Programming #Big_O_Time_O(M+max*N)_Space_O(M+N+max)
// #2024_05_27_Time_5_ms_(70.91%)_Space_10.8_MB_(74.12%)

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        int maxLen = 0;
        vector<bool> flag(s.length() + 1, false);

        for (const string& word : wordDict) {
            set.insert(word);
            maxLen = max(maxLen, (int)word.length());
        }

        for (int i = 1; i <= maxLen; ++i) {
            if (dfs(s, 0, i, maxLen, set, flag)) {
                return true;
            }
        }
        return false;
    }

    private:
    bool dfs(const string& s, int start, int end, int maxLen, unordered_set<string>& set, vector<bool>& flag) {
        if (!flag[end] && set.count(s.substr(start, end - start))) {
            flag[end] = true;
            if (end == s.length()) {
                return true;
            }
            for (int i = 1; i <= maxLen; ++i) {
                if (end + i <= s.length() && dfs(s, end, end + i, maxLen, set, flag)) {
                    return true;
                }
            }
        }
        return false;
    }
};
