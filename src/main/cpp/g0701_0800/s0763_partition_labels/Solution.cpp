// #Medium #String #Hash_Table #Greedy #Two_Pointers #Data_Structure_II_Day_7_String
// #Big_O_Time_O(n)_Space_O(1) #2024_05_21_Time_0_ms_(100.00%)_Space_7.8_MB_(95.32%)

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> partitionLabels(const std::string& s) {
        std::vector<int> result;
        std::vector<int> position(26, 0);
        
        // Store the last position of each character
        for (int i = 0; i < s.size(); ++i) {
            position[s[i] - 'a'] = i;
        }
        
        int max = 0;
        int prev = -1;
        
        for (int i = 0; i < s.size(); ++i) {
            // Update max position of current character
            if (position[s[i] - 'a'] > max) {
                max = position[s[i] - 'a'];
            }
            
            // If current index reaches max, partition found
            if (i == max) {
                result.push_back(i - prev);
                prev = i;
            }
        }
        
        return result;
    }
};
