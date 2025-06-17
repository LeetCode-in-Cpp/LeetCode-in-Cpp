// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #Dynamic_Programming #Depth_First_Search
// #Tree #Binary_Tree #Udemy_Tree_Stack_Queue #Top_Interview_150_Binary_Tree_General
// #Big_O_Time_O(N)_Space_O(N) #2024_05_27_Time_12_ms_(92.72%)_Space_26_MB_(75.74%)

#include <algorithm>
#include <climits>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxSum;

    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // to avoid negative values on the left side, we compare them with 0
        int left = std::max(0, helper(root->left));
        int right = std::max(0, helper(root->right));
        int current = root->val + left + right;
        maxSum = std::max(maxSum, current);
        return root->val + std::max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        helper(root);
        return maxSum;
    }
};
