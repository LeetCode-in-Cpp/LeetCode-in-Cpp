// #Medium #Top_100_Liked_Questions #Array #Binary_Search #Algorithm_II_Day_2_Binary_Search
// #Binary_Search_I_Day_12 #Udemy_Binary_Search #Top_Interview_150_Binary_Search
// #Big_O_Time_O(log_N)_Space_O(log_N) #2024_05_27_Time_2_ms_(59.43%)_Space_12.5_MB_(58.76%)

#include <vector>

class Solution {
private:
    int findMinUtil(std::vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        int mid = (l + r) / 2;
        if (mid == l && nums[mid] < nums[r]) {
            return nums[l];
        }
        if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
            return nums[mid];
        }
        if (nums[mid] < nums[l]) {
            return findMinUtil(nums, l, mid - 1);
        } else if (nums[mid] > nums[r]) {
            return findMinUtil(nums, mid + 1, r);
        }
        return findMinUtil(nums, l, mid - 1);
    }

public:
    int findMin(std::vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        return findMinUtil(nums, l, r);
    }
};
