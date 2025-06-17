// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #String #Hash_Table #Sorting
// #Data_Structure_II_Day_8_String #Programming_Skills_II_Day_11 #Udemy_Strings
// #Top_Interview_150_Hashmap #Big_O_Time_O(n*k_log_k)_Space_O(n)
// #2024_05_25_Time_18_ms_(96.16%)_Space_22.7_MB_(93.37%)

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hm;
        for (const auto& s : strs) {
            std::string temp = s;
            std::sort(temp.begin(), temp.end());
            hm[temp].push_back(s);
        }
        std::vector<std::vector<std::string>> result;
        for (auto& pair : hm) {
            result.push_back(std::move(pair.second));
        }
        return result;
    }
};
