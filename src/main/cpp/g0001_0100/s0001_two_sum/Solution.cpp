// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table
// #Data_Structure_I_Day_2_Array #Level_1_Day_13_Hashmap #Udemy_Arrays #Big_O_Time_O(n)_Space_O(n)
// #2024_05_12_Time_8_ms_(79.20%)_Space_13.5_MB_(49.33%)

class Solution {
public:
    map<int,int> mp;
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                return {mp[nums[i]], i};
            } else {
                mp[target-nums[i]] = i;
            }
        }
        return {};
    }
};
