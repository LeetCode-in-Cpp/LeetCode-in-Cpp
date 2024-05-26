// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming #Two_Pointers
// #Stack #Monotonic_Stack #Dynamic_Programming_I_Day_9 #Udemy_Two_Pointers
// #Big_O_Time_O(n)_Space_O(1) #2024_05_24_Time_3_ms_(99.04%)_Space_22.2_MB_(96.00%)

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        int lowerWall = 0;
        while (l < r) {
            int lVal = height[l];
            int rVal = height[r];
            if (lVal < rVal) {
                lowerWall = max(lVal, lowerWall);
                res += lowerWall - lVal;
                l++;
            } else {
                lowerWall = max(rVal, lowerWall);
                res += lowerWall - rVal;
                r--;
            }
        }
        return res;
    }
};
