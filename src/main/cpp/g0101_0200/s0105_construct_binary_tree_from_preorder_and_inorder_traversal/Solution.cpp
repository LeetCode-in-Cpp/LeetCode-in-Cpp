// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table #Tree #Binary_Tree
// #Divide_and_Conquer #Data_Structure_II_Day_15_Tree #Top_Interview_150_Binary_Tree_General
// #Big_O_Time_O(N)_Space_O(N) #2024_05_27_Time_3_ms_(99.30%)_Space_26.1_MB_(37.92%)

#include <vector>
#include <unordered_map>

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
    int j;
    std::unordered_map<int, int> map;

public:
    Solution() : j(0) {}

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        map.clear();
        j = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            map[inorder[i]] = i;
        }
        return answer(preorder, inorder, 0, preorder.size() - 1);
    }

private:
    TreeNode* answer(const std::vector<int>& preorder, const std::vector<int>& inorder, int start, int end) {
        if (start > end || j >= preorder.size()) {
            return nullptr;
        }
        int value = preorder[j++];
        int index = map[value];
        TreeNode* node = new TreeNode(value);
        node->left = answer(preorder, inorder, start, index - 1);
        node->right = answer(preorder, inorder, index + 1, end);
        return node;
    }
};
