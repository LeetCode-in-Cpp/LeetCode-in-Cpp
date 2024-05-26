// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Depth_First_Search #Tree #Binary_Tree
// #Stack #Data_Structure_I_Day_10_Tree #Udemy_Tree_Stack_Queue #Big_O_Time_O(n)_Space_O(n)
// #2024_05_26_Time_0_ms_(100.00%)_Space_9.8_MB_(40.16%)

/*
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
    vector<int> a;
    void inord(TreeNode* root)
    {
        if(!root) return;
        if(root->left) inord(root->left);
        a.push_back(root->val);
        if(root->right) inord(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inord(root);
        return a;
    }
};
