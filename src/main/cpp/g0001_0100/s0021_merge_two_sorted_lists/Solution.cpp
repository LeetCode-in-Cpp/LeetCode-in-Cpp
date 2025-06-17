// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Linked_List #Recursion
// #Data_Structure_I_Day_7_Linked_List #Algorithm_I_Day_10_Recursion_Backtracking
// #Level_1_Day_3_Linked_List #Udemy_Linked_List #Top_Interview_150_Linked_List
// #Big_O_Time_O(m+n)_Space_O(m+n) #2024_05_23_Time_0_ms_(100.00%)_Space_18.5_MB_(7.09%)

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* list = &dummy;
        
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr && l2 != nullptr) {
                if (l1->val <= l2->val) {
                    list->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    list->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            } else if (l1 != nullptr) {
                list->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                list->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            list = list->next;
        }
        
        return dummy.next;
    }
};
