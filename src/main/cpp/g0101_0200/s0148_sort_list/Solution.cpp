// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Sorting #Two_Pointers #Linked_List
// #Divide_and_Conquer #Merge_Sort #Level_2_Day_4_Linked_List #Top_Interview_150_Divide_and_Conquer
// #Big_O_Time_O(log(N))_Space_O(log(N)) #2024_05_27_Time_130_ms_(50.49%)_Space_73.5_MB_(37.52%)

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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = slow;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        ListNode* first = sortList(head);
        ListNode* second = sortList(slow);
        ListNode* res = new ListNode(1);
        ListNode* cur = res;
        while (first != nullptr || second != nullptr) {
            if (first == nullptr) {
                cur->next = second;
                break;
            } else if (second == nullptr) {
                cur->next = first;
                break;
            } else if (first->val <= second->val) {
                cur->next = first;
                first = first->next;
                cur = cur->next;
            } else {
                cur->next = second;
                second = second->next;
                cur = cur->next;
            }
        }
        return res->next;
    }
};
