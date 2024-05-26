// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Binary_Search
// #Algorithm_II_Day_1_Binary_Search #Binary_Search_I_Day_5 #Big_O_Time_O(log_n)_Space_O(1)
// #2024_05_24_Time_0_ms_(100.00%)_Space_15.9_MB_(98.52%)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        ans[0] = helper(nums, target, false);
        ans[1] = helper(nums, target, true);
        return ans;
    }

private:
    int helper(const vector<int>& nums, int target, bool findLast) {
        int l = 0;
        int r = nums.size() - 1;
        int result = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                result = mid;
            }
            if (nums[mid] < target || (nums[mid] == target && findLast)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};
