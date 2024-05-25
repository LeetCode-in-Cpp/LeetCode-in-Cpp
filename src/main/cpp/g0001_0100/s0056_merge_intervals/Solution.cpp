// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Sorting
// #Data_Structure_II_Day_2_Array #Level_2_Day_17_Interval #Udemy_2D_Arrays/Matrix
// #Big_O_Time_O(n_log_n)_Space_O(n) #2024_05_25_Time_19_ms_(85.51%)_Space_22.8_MB_(41.78%)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> lastInterval = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > lastInterval[1]){
                ans.push_back(lastInterval);
                lastInterval = intervals[i];
            } else {
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            }
        }
        ans.push_back(lastInterval);
        return ans;
    }
};
