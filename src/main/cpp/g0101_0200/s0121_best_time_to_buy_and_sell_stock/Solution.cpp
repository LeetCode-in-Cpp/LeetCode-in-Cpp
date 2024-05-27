// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming
// #Data_Structure_I_Day_3_Array #Dynamic_Programming_I_Day_7 #Level_1_Day_5_Greedy #Udemy_Arrays
// #Big_O_Time_O(N)_Space_O(1) #2024_05_27_Time_69_ms_(96.21%)_Space_95.8_MB_(68.67%)

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int maxProfit = 0;
        int minPrice = prices[0];
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > minPrice) {
                maxProfit = std::max(maxProfit, prices[i] - minPrice);
            } else {
                minPrice = prices[i];
            }
        }
        return maxProfit;
    }
};
