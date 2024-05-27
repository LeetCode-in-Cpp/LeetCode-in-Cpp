// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Hash_Table #Linked_List
// #Programming_Skills_II_Day_14 #Udemy_Linked_List #Big_O_Time_O(N)_Space_O(N)
// #2024_05_27_Time_5_ms_(65.69%)_Space_12.9_MB_(73.88%)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* curr = head;
        // First pass to create cloned nodes and insert them between original nodes
        while (curr != nullptr) {
            Node* clonedNode = new Node(curr->val, curr->next, nullptr);
            curr->next = clonedNode;
            curr = clonedNode->next;
        }
        // Second pass to update random pointers of cloned nodes
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // Third pass to separate original and cloned nodes
        curr = head;
        Node* newHead = curr->next;
        while (curr != nullptr) {
            Node* clonedNode = curr->next;
            curr->next = clonedNode->next;
            if (clonedNode->next != nullptr) {
                clonedNode->next = clonedNode->next->next;
            }
            curr = curr->next;
        }
        return newHead;
    }
};
