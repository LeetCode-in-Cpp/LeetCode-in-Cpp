// #Hard #Top_100_Liked_Questions #Array #Heap_Priority_Queue #Sliding_Window #Queue
// #Monotonic_Queue #Udemy_Arrays #Big_O_Time_O(n*k)_Space_O(n+k)
// #2024_05_24_Time_164_ms_(80.55%)_Space_132.2_MB_(99.45%)

#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> res(n - k + 1);
        int x = 0;
        std::deque<int> dq;
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            while (!dq.empty() && dq.back() < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if (j - i + 1 == k) {
                res[x] = dq.front();
                ++x;
                if (dq.front() == nums[i]) {
                    dq.pop_front();
                }
                ++i;
            }
            ++j;
        }
        return res;
    }
};
