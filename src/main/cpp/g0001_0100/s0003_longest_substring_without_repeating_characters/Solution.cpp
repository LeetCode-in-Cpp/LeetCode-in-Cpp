// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Hash_Table #Sliding_Window
// #Algorithm_I_Day_6_Sliding_Window #Level_2_Day_14_Sliding_Window/Two_Pointer #Udemy_Strings
// #Big_O_Time_O(n)_Space_O(1) #2024_05_12_Time_15_ms_(55.04%)_Space_16.2_MB_(10.78%)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> mp;
        int i = 0, j = 0;
        int ans = 0;
        while (j < s.length()) {
            if (mp.find(s[j]) != mp.end()) {
                mp.erase(s[i]);
                i++;
            } else if(j < s.length()) {
                mp[s[j]]++;
                j++;
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};
