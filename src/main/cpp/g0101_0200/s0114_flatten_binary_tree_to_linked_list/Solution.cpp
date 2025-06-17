// #Medium #Top_100_Liked_Questions #Depth_First_Search #Tree #Binary_Tree #Stack #Linked_List
// #Udemy_Linked_List #Top_Interview_150_Binary_Tree_General #Big_O_Time_O(N)_Space_O(N)
// #2024_05_27_Time_0_ms_(100.00%)_Space_15.6_MB_(59.01%)

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
    void flatten(TreeNode* root) {
        if (root != nullptr) {
            findTail(root);
        }
    }

private:
    TreeNode* findTail(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        TreeNode* tail;

        // Find the tail of left subtree, tail means the most left leaf
        if (left != nullptr) {
            tail = findTail(left);
            // Stitch the right subtree below the tail
            root->left = nullptr;
            root->right = left;
            tail->right = right;
        } else {
            tail = root;
        }

        // Find tail of the right subtree
        if (tail->right == nullptr) {
            return tail;
        } else {
            return findTail(tail->right);
        }
    }
};
