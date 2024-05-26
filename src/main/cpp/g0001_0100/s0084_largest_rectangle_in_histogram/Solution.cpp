// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #Array #Stack #Monotonic_Stack
// #Big_O_Time_O(n_log_n)_Space_O(log_n) #2024_05_26_Time_89_ms_(95.11%)_Space_76.8_MB_(99.97%)

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        return largestArea(heights, 0, heights.size());
    }

private:
    int largestArea(const std::vector<int>& a, int start, int limit) {
        if (a.empty()) {
            return 0;
        }
        if (start == limit) {
            return 0;
        }
        if (limit - start == 1) {
            return a[start];
        }
        if (limit - start == 2) {
            int maxOfTwoBars = std::max(a[start], a[start + 1]);
            int areaFromTwo = std::min(a[start], a[start + 1]) * 2;
            return std::max(maxOfTwoBars, areaFromTwo);
        }
        if (checkIfSorted(a, start, limit)) {
            int maxWhenSorted = 0;
            for (int i = start; i < limit; i++) {
                if (a[i] * (limit - i) > maxWhenSorted) {
                    maxWhenSorted = a[i] * (limit - i);
                }
            }
            return maxWhenSorted;
        } else {
            int minInd = findMinInArray(a, start, limit);
            return maxOfThreeNums(
                largestArea(a, start, minInd),
                a[minInd] * (limit - start),
                largestArea(a, minInd + 1, limit)
            );
        }
    }

    int findMinInArray(const std::vector<int>& a, int start, int limit) {
        int min = INT_MAX;
        int minIndex = -1;
        for (int index = start; index < limit; index++) {
            if (a[index] < min) {
                min = a[index];
                minIndex = index;
            }
        }
        return minIndex;
    }

    bool checkIfSorted(const std::vector<int>& a, int start, int limit) {
        for (int i = start + 1; i < limit; i++) {
            if (a[i] < a[i - 1]) {
                return false;
            }
        }
        return true;
    }

    int maxOfThreeNums(int a, int b, int c) {
        return std::max(std::max(a, b), c);
    }
};
