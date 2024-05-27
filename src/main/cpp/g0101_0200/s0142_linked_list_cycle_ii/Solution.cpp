// #Medium #Top_100_Liked_Questions #Hash_Table #Two_Pointers #Linked_List
// #Data_Structure_II_Day_10_Linked_List #Level_1_Day_4_Linked_List #Udemy_Linked_List
// #Big_O_Time_O(N)_Space_O(1) #2024_05_27_Time_9_ms_(47.48%)_Space_10.2_MB_(18.65%)

class Solution {
    public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            // Intersected inside the loop.
            if (slow == fast) {
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
