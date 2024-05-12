// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Math #Linked_List #Recursion
// #Data_Structure_II_Day_10_Linked_List #Programming_Skills_II_Day_15
// #Big_O_Time_O(max(N,M))_Space_O(max(N,M)) #2024_05_12_Time_15_ms_(87.75%)_Space_75.4_MB_(99.46%)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* copy1=l1;
        ListNode* copy2=l2;
        int sum = 0, carry = 0;
        while (copy1 && copy2) {
            sum = copy1->val + copy2->val + carry;
            carry = sum / 10;
            copy1->val = sum % 10;
            if (!copy1->next && !copy2->next && carry) {
                copy1->next = new ListNode(1);
                copy1 = NULL;
                break;
            }
            if (!copy1->next && copy2->next) {
                copy1->next = copy2->next;
                copy2 = copy2->next;
                copy1 = NULL;
                break;
            }
            copy1=copy1->next;
            copy2=copy2->next;
        }
        while (copy1) {
            if (!carry)
                break;
            sum = copy1->val + carry;
            carry = sum / 10;
            copy1->val = sum % 10;
            if (!copy1->next && carry) {
                copy1->next = new ListNode(1);
                break;
            }
            copy1 = copy1->next;
        }
        while(copy2) {
            if (!carry)
                break;
            sum = copy2->val + carry;
            carry = sum / 10;
            copy2->val = sum % 10;
            if (!copy2->next && carry){
                copy2->next = new ListNode(1);
                break;
            }
            copy2 = copy2->next;
        }
        return l1;
    }
};
