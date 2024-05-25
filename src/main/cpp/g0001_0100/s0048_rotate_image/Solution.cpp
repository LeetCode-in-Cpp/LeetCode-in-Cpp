// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Math #Matrix
// #Data_Structure_II_Day_3_Array #Programming_Skills_II_Day_7 #Udemy_2D_Arrays/Matrix
// #Big_O_Time_O(n^2)_Space_O(1) #2024_05_25_Time_0_ms_(100.00%)_Space_9.1_MB_(21.55%)

#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                std::vector<std::vector<int>> pos = {
                    {i, j}, 
                    {j, n - 1 - i}, 
                    {n - 1 - i, n - 1 - j}, 
                    {n - 1 - j, i}
                };
                int t = matrix[pos[0][0]][pos[0][1]];
                for (int k = 1; k < pos.size(); ++k) {
                    int temp = matrix[pos[k][0]][pos[k][1]];
                    matrix[pos[k][0]][pos[k][1]] = t;
                    t = temp;
                }
                matrix[pos[0][0]][pos[0][1]] = t;
            }
        }
    }
};
