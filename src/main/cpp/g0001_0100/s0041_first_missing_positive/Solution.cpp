// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table #Udemy_Arrays
// #Big_O_Time_O(n)_Space_O(n) #2024_05_24_Time_42_ms_(69.19%)_Space_53.4_MB_(25.71%)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;i++) {
            if (nums[i]<=0) {
                nums[i]=INT_MAX;
            }
        }
        for (int i=0;i<n;i++) {
            if (abs(nums[i]) <= n && nums[abs(nums[i])-1] > 0) {
                nums[abs(nums[i])-1] *= -1;
            }
        }
        for (int i=0;i<n;i++) {
            if (nums[i] > 0) {
                return i+1;
            }
        }
        return n+1;
    }
};
