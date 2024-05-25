// #Medium #Top_100_Liked_Questions #Array #Dynamic_Programming #Matrix
// #Dynamic_Programming_I_Day_16 #Udemy_Dynamic_Programming #Big_O_Time_O(m*n)_Space_O(m*n)
// #2024_05_25_Time_2_ms_(95.63%)_Space_12.5_MB_(61.47%)

#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.size() == 1 && grid[0].size() == 1) {
            return grid[0][0];
        }

        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dm(m, std::vector<int>(n, 0));
        int s = 0;

        // Initialize the last column
        for (int r = m - 1; r >= 0; --r) {
            dm[r][n - 1] = grid[r][n - 1] + s;
            s += grid[r][n - 1];
        }

        s = 0;
        // Initialize the last row
        for (int c = n - 1; c >= 0; --c) {
            dm[m - 1][c] = grid[m - 1][c] + s;
            s += grid[m - 1][c];
        }

        return recur(grid, dm, 0, 0);
    }

private:
    int recur(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& dm, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        if (dm[r][c] == 0 && r != m - 1 && c != n - 1) {
            dm[r][c] = grid[r][c] + std::min(recur(grid, dm, r + 1, c), recur(grid, dm, r, c + 1));
        }
        return dm[r][c];
    }
};
