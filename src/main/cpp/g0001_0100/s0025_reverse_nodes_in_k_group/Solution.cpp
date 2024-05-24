// #Hard #Top_100_Liked_Questions #Linked_List #Recursion #Data_Structure_II_Day_13_Linked_List
// #Udemy_Linked_List #Big_O_Time_O(n)_Space_O(k)
// #2024_05_24_Time_3_ms_(98.79%)_Space_14.9_MB_(96.07%)

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) {
            return head;
        }

        // Check if there are at least k nodes remaining
        ListNode* len = head;
        for (int j = 0; j < k; ++j) {
            if (len == nullptr) {
                return head; // Less than k nodes, return the list as is
            }
            len = len->next;
        }

        // Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        for (int i = 0; i < k; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Recursively call for the next k nodes
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};
