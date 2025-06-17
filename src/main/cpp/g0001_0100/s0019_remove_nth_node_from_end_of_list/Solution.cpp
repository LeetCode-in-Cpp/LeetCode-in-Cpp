// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Two_Pointers #Linked_List
// #Algorithm_I_Day_5_Two_Pointers #Level_2_Day_3_Linked_List #Top_Interview_150_Linked_List
// #Big_O_Time_O(L)_Space_O(L) #2024_05_23_Time_0_ms_(100.00%)_Space_13.2_MB_(92.45%)

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
private:
    int n;

    void removeNth(ListNode* node) {
        if (node->next == nullptr) {
            return;
        }
        removeNth(node->next);
        n--;
        if (n == 0) {
            node->next = node->next->next;
        }
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        this->n = n;
        ListNode* node = new ListNode(0, head);
        removeNth(node);
        ListNode* newHead = node->next;
        delete node; // clean up the temporary node
        return newHead;
    }
};
