// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Sorting #Two_Pointers
// #Data_Structure_II_Day_2_Array #Udemy_Arrays #Big_O_Time_O(n)_Space_O(1)
// #2024_05_26_Time_0_ms_(100.00%)_Space_9.9_MB_(32.84%)

#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int zeroes = 0;
        int ones = 0;

        // Count the number of zeros and place them in the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[zeroes++] = 0;
            } else if (nums[i] == 1) {
                ones++;
            }
        }

        // Place ones after the zeros
        for (int j = zeroes; j < zeroes + ones; j++) {
            nums[j] = 1;
        }

        // Place twos after the ones
        for (int k = zeroes + ones; k < nums.size(); k++) {
            nums[k] = 2;
        }
    }
};
