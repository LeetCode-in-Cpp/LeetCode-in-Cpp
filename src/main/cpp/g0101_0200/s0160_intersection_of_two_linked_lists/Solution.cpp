// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Hash_Table #Two_Pointers #Linked_List
// #Data_Structure_II_Day_11_Linked_List #Udemy_Linked_List #Big_O_Time_O(M+N)_Space_O(1)
// #2024_05_26_Time_30_ms_(96.07%)_Space_17.2_MB_(20.91%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        while (node1 != node2) {
            node1 = (node1 == nullptr) ? headB : node1->next;
            node2 = (node2 == nullptr) ? headA : node2->next;
        }
        return node1;
    }
};
