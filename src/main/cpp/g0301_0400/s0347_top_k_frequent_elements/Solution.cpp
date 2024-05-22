// #Medium #Top_100_Liked_Questions #Array #Hash_Table #Sorting #Heap_Priority_Queue #Counting
// #Divide_and_Conquer #Quickselect #Bucket_Sort #Data_Structure_II_Day_20_Heap_Priority_Queue
// #Big_O_Time_O(n*log(n))_Space_O(k) #2024_05_22_Time_11_ms_(69.14%)_Space_16.3_MB_(88.53%)

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        // Min heap of <number, frequency>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Filter with min heap
        int j = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            if (i == nums.size() || nums[i] != nums[j]) {
                minHeap.push({i - j, nums[j]});
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
                j = i;
            }
        }

        // Convert to int array
        vector<int> result(k);
        for (int i = k - 1; i >= 0; --i) {
            result[i] = minHeap.top().second;
            minHeap.pop();
        }

        return result;
    }
};
