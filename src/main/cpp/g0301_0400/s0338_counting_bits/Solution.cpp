// #Easy #Dynamic_Programming #Bit_Manipulation #LeetCode_75_Bit_Manipulation
// #Udemy_Bit_Manipulation #Big_O_Time_O(num)_Space_O(num)
// #2024_05_22_Time_0_ms_(100.00%)_Space_8.9_MB_(80.27%)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        int borderPos = 1;
        int incrPos = 1;
        for (int i = 1; i <= num; ++i) {
            // when we reach power of 2, reset borderPos and incrPos
            if (incrPos == borderPos) {
                result[i] = 1;
                incrPos = 1;
                borderPos = i;
            } else {
                result[i] = 1 + result[incrPos++];
            }
        }
        return result;
    }
};
