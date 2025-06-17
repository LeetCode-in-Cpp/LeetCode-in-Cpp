// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #Heap_Priority_Queue #Linked_List
// #Divide_and_Conquer #Merge_Sort #Top_Interview_150_Divide_and_Conquer
// #Big_O_Time_O(k*n*log(k))_Space_O(log(k)) #2024_05_23_Time_7_ms_(98.72%)_Space_16.5_MB_(98.90%)

#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeKLists(lists, 0, lists.size());
    }

private:
    ListNode* mergeKLists(vector<ListNode*>& lists, int leftIndex, int rightIndex) {
        if (rightIndex > leftIndex + 1) {
            int mid = (leftIndex + rightIndex) / 2;
            ListNode* left = mergeKLists(lists, leftIndex, mid);
            ListNode* right = mergeKLists(lists, mid, rightIndex);
            return mergeTwoLists(left, right);
        } else {
            return lists[leftIndex];
        }
    }

    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        ListNode* res;
        if (left->val <= right->val) {
            res = left;
            left = left->next;
        } else {
            res = right;
            right = right->next;
        }
        ListNode* node = res;
        while (left != nullptr || right != nullptr) {
            if (left == nullptr) {
                node->next = right;
                right = right->next;
            } else if (right == nullptr) {
                node->next = left;
                left = left->next;
            } else {
                if (left->val <= right->val) {
                    node->next = left;
                    left = left->next;
                } else {
                    node->next = right;
                    right = right->next;
                }
            }
            node = node->next;
        }
        return res;
    }
};
