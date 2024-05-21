// #Medium #String #Dynamic_Programming #Big_O_Time_O(n^2)_Space_O(n)
// #2024_05_21_Time_3_ms_(94.97%)_Space_7.5_MB_(85.16%)

#include <vector>
#include <string>

class Solution {
private:
    void expand(const std::vector<char>& a, int l, int r, int& res) {
        while (l >= 0 && r < a.size()) {
            if (a[l] != a[r]) {
                return;
            } else {
                res++;
                l--;
                r++;
            }
        }
    }

public:
    int countSubstrings(const std::string& s) {
        std::vector<char> a(s.begin(), s.end());
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            expand(a, i, i, res);
            expand(a, i, i + 1, res);
        }
        return res;
    }
};
