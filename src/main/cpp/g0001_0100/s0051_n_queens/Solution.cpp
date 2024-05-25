// #Hard #Top_100_Liked_Questions #Array #Backtracking #Big_O_Time_O(N!)_Space_O(N)
// #2024_05_25_Time_3_ms_(80.52%)_Space_11.3_MB_(29.15%)

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<bool> pos(n + 2 * n - 1 + 2 * n - 1, false);
        std::vector<int> pos2(n, 0);
        std::vector<std::vector<std::string>> ans;
        helper(n, 0, pos, pos2, ans);
        return ans;
    }

private:
    void helper(int n, int row, std::vector<bool>& pos, std::vector<int>& pos2, std::vector<std::vector<std::string>>& ans) {
        if (row == n) {
            construct(n, pos2, ans);
            return;
        }
        for (int i = 0; i < n; ++i) {
            int index = n + 2 * n - 1 + n - 1 + i - row;
            if (pos[i] || pos[n + i + row] || pos[index]) {
                continue;
            }
            pos[i] = true;
            pos[n + i + row] = true;
            pos[index] = true;
            pos2[row] = i;
            helper(n, row + 1, pos, pos2, ans);
            pos[i] = false;
            pos[n + i + row] = false;
            pos[index] = false;
        }
    }

    void construct(int n, std::vector<int>& pos, std::vector<std::vector<std::string>>& ans) {
        std::vector<std::string> sol;
        for (int r = 0; r < n; ++r) {
            std::string queenRow(n, '.');
            queenRow[pos[r]] = 'Q';
            sol.push_back(queenRow);
        }
        ans.push_back(sol);
    }
};
