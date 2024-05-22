// #Easy #Top_100_Liked_Questions #Depth_First_Search #Tree #Binary_Tree #Level_2_Day_7_Tree
// #Udemy_Tree_Stack_Queue #Big_O_Time_O(n)_Space_O(n)
// #2024_05_22_Time_4_ms_(95.38%)_Space_22.1_MB_(76.43%)

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
    int diameter;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        diameterOfBinaryTreeUtil(root);
        return diameter;
    }

private:
    int diameterOfBinaryTreeUtil(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftLength = root->left != nullptr ? 1 + diameterOfBinaryTreeUtil(root->left) : 0;
        int rightLength = root->right != nullptr ? 1 + diameterOfBinaryTreeUtil(root->right) : 0;
        diameter = max(diameter, leftLength + rightLength);
        return max(leftLength, rightLength);
    }
};
