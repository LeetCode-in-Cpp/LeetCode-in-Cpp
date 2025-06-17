// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Math #Two_Pointers
// #Algorithm_I_Day_2_Two_Pointers #Udemy_Arrays #Top_Interview_150_Array/String
// #Big_O_Time_O(n)_Space_O(1) #2024_05_26_Time_18_ms_(77.84%)_Space_27.3_MB_(54.21%)

#include <vector>
using namespace std;

class Solution {
private:
    void reverse(vector<int>& nums, int l, int r) {
        while (l <= r) {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int t = n - (k % n);
        reverse(nums, 0, t - 1);
        reverse(nums, t, n - 1);
        reverse(nums, 0, n - 1);
    }
};
