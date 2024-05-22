// #Medium #Top_100_Liked_Questions #String #Hash_Table #Sliding_Window
// #Algorithm_II_Day_5_Sliding_Window #Programming_Skills_II_Day_12
// #Level_1_Day_12_Sliding_Window/Two_Pointer #Big_O_Time_O(n+m)_Space_O(1)
// #2024_05_22_Time_0_ms_(100.00%)_Space_9.9_MB_(68.79%)

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> map(26, 0);
        for (char c : p) {
            map[c - 'a']++;
        }

        vector<int> res;
        int i = 0, j = 0;

        while (i < s.length()) {
            int idx = s[i] - 'a';
            // Add the new character
            map[idx]--;

            // If the length is greater than window's length, pop the left character in the window
            if (i >= p.length()) {
                map[s[j++] - 'a']++;
            }

            bool finish = true;
            for (int k = 0; k < 26; k++) {
                // If it is not an anagram of string p
                if (map[k] != 0) {
                    finish = false;
                    break;
                }
            }

            if (i >= p.length() - 1 && finish) {
                res.push_back(j);
            }

            i++;
        }

        return res;
    }
};
