// #Medium #Depth_First_Search #Tree #Binary_Tree #LeetCode_75_Binary_Tree/DFS #Level_2_Day_7_Tree
// #Big_O_Time_O(n)_Space_O(n) #2024_05_22_Time_15_ms_(70.45%)_Space_17.4_MB_(87.83%)

#include <cstddef>

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
    int count = 0;

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        }
        helper(root, targetSum, 0);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }

    void helper(TreeNode* node, int targetSum, long currSum) {
        if (node == NULL) {
            return;
        }
        currSum += node->val;
        if (targetSum == currSum) {
            count++;
        }
        if (node->left != NULL) {
            helper(node->left, targetSum, currSum);
        }
        if (node->right != NULL) {
            helper(node->right, targetSum, currSum);
        }
    }
};
