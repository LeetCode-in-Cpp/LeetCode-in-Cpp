// #Medium #Top_100_Liked_Questions #Depth_First_Search #Tree #Binary_Tree #Binary_Search_Tree
// #Data_Structure_II_Day_17_Tree #Level_2_Day_9_Binary_Search_Tree
// #Top_Interview_150_Binary_Search_Tree #Big_O_Time_O(n)_Space_O(n)
// #2024_05_24_Time_7_ms_(94.52%)_Space_22.5_MB_(58.62%)

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
    int k;
    int count = 0;
    int val;

public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        calculate(root);
        return val;
    }

private:
    void calculate(TreeNode* node) {
        if (node->left == nullptr && node->right == nullptr) {
            count++;
            if (count == k) {
                val = node->val;
            }
            return;
        }
        if (node->left != nullptr) {
            calculate(node->left);
        }
        count++;
        if (count == k) {
            val = node->val;
            return;
        }
        if (node->right != nullptr) {
            calculate(node->right);
        }
    }
};
