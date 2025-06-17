// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Dynamic_Programming #Math #Memoization
// #Algorithm_I_Day_12_Dynamic_Programming #Dynamic_Programming_I_Day_2
// #Level_1_Day_10_Dynamic_Programming #Udemy_Dynamic_Programming #Top_Interview_150_1D_DP
// #Big_O_Time_O(n)_Space_O(n) #2024_05_26_Time_0_ms_(100.00%)_Space_7.3_MB_(31.62%)

#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return n;
        }
        std::vector<int> cache(n);
        // Creating a cache or DP to store the result
        // so that we don't have to iterate multiple times
        // for the same values.

        // For 0 and 1 the result array i.e cache values would be 1 and 2
        // In loop we are just getting ith values i.e 5th step values from
        // i-1 and i-2 which are 4th step and 3rd step values.
        cache[0] = 1;
        cache[1] = 2;
        for (int i = 2; i < n; i++) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
        return cache[n - 1];
    }
};
