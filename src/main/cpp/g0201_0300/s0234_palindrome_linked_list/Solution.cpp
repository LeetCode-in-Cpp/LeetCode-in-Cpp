// #Easy #Top_100_Liked_Questions #Two_Pointers #Stack #Linked_List #Recursion
// #Level_2_Day_3_Linked_List #Udemy_Linked_List #Big_O_Time_O(n)_Space_O(1)
// #2024_05_24_Time_154_ms_(83.63%)_Space_116.7_MB_(68.62%)

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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* right = head;
        // Calculate the length
        while (right != nullptr) {
            right = right->next;
            len++;
        }
        // Reverse the right half of the list
        len = len / 2;
        right = head;
        for (int i = 0; i < len; i++) {
            right = right->next;
        }
        ListNode* prev = nullptr;
        while (right != nullptr) {
            ListNode* next = right->next;
            right->next = prev;
            prev = right;
            right = next;
        }
        // Compare left half and right half
        for (int i = 0; i < len; i++) {
            if (prev != nullptr && head->val == prev->val) {
                head = head->next;
                prev = prev->next;
            } else {
                return false;
            }
        }
        return true;
    }
};
