// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Depth_First_Search
// #Breadth_First_Search #Graph #Topological_Sort #Big_O_Time_O(N)_Space_O(N)
// #2024_05_26_Time_15_ms_(70.71%)_Space_16.9_MB_(73.42%)

#include <vector>

class Solution {
private:
    const int WHITE = 0;
    const int GRAY = 1;
    const int BLACK = 2;

public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        std::vector<int> colors(numCourses, WHITE);
        for (int i = 0; i < numCourses; i++) {
            if (colors[i] == WHITE && !adj[i].empty() && hasCycle(adj, i, colors)) {
                return false;
            }
        }
        return true;
    }

private:
    bool hasCycle(const std::vector<std::vector<int>>& adj, int node, std::vector<int>& colors) {
        colors[node] = GRAY;
        for (int nei : adj[node]) {
            if (colors[nei] == GRAY) {
                return true;
            }
            if (colors[nei] == WHITE && hasCycle(adj, nei, colors)) {
                return true;
            }
        }
        colors[node] = BLACK;
        return false;
    }
};
