// #Easy #Top_100_Liked_Questions #Array #Two_Pointers #LeetCode_75_Two_Pointers
// #Algorithm_I_Day_3_Two_Pointers #Programming_Skills_I_Day_6_Array #Udemy_Arrays
// #Big_O_Time_O(n)_Space_O(1) #2024_05_24_Time_6_ms_(98.89%)_Space_21.6_MB_(73.28%)

#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int firstZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(firstZero, i, nums);
                firstZero++;
            }
        }
    }

private:
    void swap(int index1, int index2, std::vector<int>& numbers) {
        int val2 = numbers[index2];
        numbers[index2] = numbers[index1];
        numbers[index1] = val2;
    }
};
