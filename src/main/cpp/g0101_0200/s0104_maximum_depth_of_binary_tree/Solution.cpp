// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Depth_First_Search #Breadth_First_Search
// #Tree #Binary_Tree #Data_Structure_I_Day_11_Tree
// #Programming_Skills_I_Day_10_Linked_List_and_Tree #Udemy_Tree_Stack_Queue
// #Big_O_Time_O(N)_Space_O(H) #2024_05_27_Time_4_ms_(78.98%)_Space_17.4_MB_(79.78%)

#include <iostream>
#include <algorithm>

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
    int maxDepth(TreeNode* root) {
        return findDepth(root);
    }

private:
    int findDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(findDepth(node->left), findDepth(node->right));
    }
};
