// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table #Sorting #Counting
// #Divide_and_Conquer #Data_Structure_II_Day_1_Array #Udemy_Famous_Algorithm
// #Big_O_Time_O(n)_Space_O(1) #2024_05_26_Time_10_ms_(95.79%)_Space_26.6_MB_(90.80%)

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int majority = nums[0];

        // For Potential Majority Element
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == majority) {
                count++;
            } else {
                if (count > 1) {
                    count--;
                } else {
                    majority = nums[i];
                }
            }
        }

        // For Confirmation
        count = 0;
        for (int num : nums) {
            if (num == majority) {
                count++;
            }
        }

        if (count >= (nums.size() / 2) + 1) {
            return majority;
        } else {
            return -1;
        }
    }
};
