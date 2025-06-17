// #Easy #Top_100_Liked_Questions #Array #Binary_Search #Algorithm_I_Day_1_Binary_Search
// #Binary_Search_I_Day_2 #Top_Interview_150_Binary_Search #Big_O_Time_O(log_n)_Space_O(1)
// #2024_05_24_Time_0_ms_(100.00%)_Space_12.1_MB_(7.57%)

#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};
