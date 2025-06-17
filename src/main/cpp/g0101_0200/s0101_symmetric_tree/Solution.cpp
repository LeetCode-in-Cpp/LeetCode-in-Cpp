// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Depth_First_Search #Breadth_First_Search
// #Tree #Binary_Tree #Data_Structure_I_Day_11_Tree #Level_2_Day_15_Tree
// #Top_Interview_150_Binary_Tree_General #Big_O_Time_O(N)_Space_O(log(N))
// #2024_05_27_Time_0_ms_(100.00%)_Space_17.4_MB_(37.66%)

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
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return helper(root->left, root->right);
    }

private:
    bool helper(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr || rightNode == nullptr) {
            return leftNode == nullptr && rightNode == nullptr;
        }
        if (leftNode->val != rightNode->val) {
            return false;
        }
        return helper(leftNode->left, rightNode->right) && helper(leftNode->right, rightNode->left);
    }
};
