// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Matrix #Backtracking
// #Algorithm_II_Day_11_Recursion_Backtracking #Top_Interview_150_Backtracking
// #Big_O_Time_O(4^(m*n))_Space_O(m*n) #2024_05_26_Time_391_ms_(63.85%)_Space_10.8_MB_(51.48%)

#include <vector>

class Solution {
    static constexpr char TOMBSTONE = '#';
    
    const vector<pair<int, int>> adj_deltas = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    
    bool is_valid(const vector<vector<char>>& board, int r, int c) {
        return r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c] != TOMBSTONE;
    }
    
    bool dfs(vector<vector<char>>& board, string_view w, int r, int c) {
        if (w.empty() || (w.size() == 1 && w[0] == board[r][c])) {
            return true;
        }
        if (w[0] != board[r][c]) {
            return false;
        }
        bool res = false;
        board[r][c] = TOMBSTONE;
        for (auto& d : adj_deltas) {
            if (int rr = r + d.first, cc = c + d.second; is_valid(board, rr, cc)) {
                res |= dfs(board, w.substr(1), rr, cc);
            }
        }
        board[r][c] = w[0];
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& board, string_view word) {
        // pruning #1
        // board has enough letters for word
        if (board.size() * board[0].size() < word.size()) {
            return false;
        }
        // pruning #2
        // all letters in word exist on board
        unordered_map<char, int> board_freq;
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                board_freq[board[r][c]]++;
            }
        }
        unordered_map<char, int> word_freq;
        for (char ch : word) {
            if (++word_freq[ch] > board_freq[ch]) {
                return false;
            }
        }
        // pruning #3
        // all adjacent letters in word exist on board
        // it can be merged with pruning #2, but it's still faster than 100%
        unordered_map<char, unordered_set<char>> adj_letters;
        for (char ch : word) {
            adj_letters[ch] = {};
        }
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (!adj_letters.count(board[r][c])) {
                    continue;
                }
                auto& st = adj_letters[board[r][c]];
                for (auto& d : adj_deltas) {
                    if (int rr = r + d.first, cc = c + d.second; is_valid(board, rr, cc)) {
                        st.insert(board[rr][cc]);
                    }
                }
            }
        }
        for (int i = 0; i < word.size(); i++) {
            if (i > 0 && adj_letters[word[i]].count(word[i - 1]) == 0) {
                return false;
            }
            if (i + 1 < word.size() && adj_letters[word[i]].count(word[i + 1]) == 0) {
                return false;
            }
        }
        // full dfs scan otherwise
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (dfs(board, word, r, c)) {
                    return true;
                }
            }
        }
        return false;
    }
};
