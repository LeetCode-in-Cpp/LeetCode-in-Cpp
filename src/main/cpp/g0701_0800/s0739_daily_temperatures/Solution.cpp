// #Medium #Top_100_Liked_Questions #Array #Stack #Monotonic_Stack #Programming_Skills_II_Day_6
// #Big_O_Time_O(n)_Space_O(n) #2024_05_21_Time_103_ms_(91.31%)_Space_100.9_MB_(86.96%)

#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> sol(n, 0);
        for (int i = n - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < n) {
                if (temperatures[i] < temperatures[j]) {
                    sol[i] = j - i;
                    break;
                } else {
                    if (sol[j] == 0) {
                        break;
                    }
                    j += sol[j];
                }
            }
        }
        return sol;
    }
};
