// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #String #Hash_Table #Sliding_Window
// #Level_2_Day_14_Sliding_Window/Two_Pointer #Top_Interview_150_Sliding_Window
// #Big_O_Time_O(s.length())_Space_O(1) #2024_05_26_Time_5_ms_(91.46%)_Space_9.2_MB_(99.62%)

#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(const std::string& s, const std::string& t) {
        std::vector<int> map(128, 0);
        for (char c : t) {
            map[c]++;
        }
        
        int count = t.size();
        int begin = 0;
        int end = 0;
        int d = INT_MAX;
        int head = 0;

        while (end < s.size()) {
            if (map[s[end++]]-- > 0) {
                count--;
            }
            
            while (count == 0) {
                if (end - begin < d) {
                    d = end - begin;
                    head = begin;
                }
                if (map[s[begin++]]++ == 0) {
                    count++;
                }
            }
        }

        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
