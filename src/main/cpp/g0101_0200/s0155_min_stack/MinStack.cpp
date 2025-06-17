// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Stack #Design
// #Data_Structure_II_Day_14_Stack_Queue #Programming_Skills_II_Day_18 #Level_2_Day_16_Design
// #Udemy_Design #Top_Interview_150_Stack #Big_O_Time_O(1)_Space_O(N)
// #2024_05_27_Time_10_ms_(96.74%)_Space_20.3_MB_(61.17%)

#include <stack>
#include <algorithm>

class MinStack {
private:
    struct Node {
        int min;
        int data;
        Node* nextNode;
        Node* previousNode;

        Node(int min, int data, Node* previousNode, Node* nextNode)
            : min(min), data(data), previousNode(previousNode), nextNode(nextNode) {}
    };

    Node* currentNode;

public:
    MinStack() : currentNode(nullptr) {}

    void push(int val) {
        if (currentNode == nullptr) {
            currentNode = new Node(val, val, nullptr, nullptr);
        } else {
            currentNode->nextNode = new Node(std::min(currentNode->min, val), val, currentNode, nullptr);
            currentNode = currentNode->nextNode;
        }
    }

    void pop() {
        if (currentNode != nullptr) {
            currentNode = currentNode->previousNode;
        }
    }

    int top() {
        if (currentNode != nullptr) {
            return currentNode->data;
        }
        return -1;
    }

    int getMin() {
        if (currentNode != nullptr) {
            return currentNode->min;
        }
        return -1;
    }

    ~MinStack() {
        while (currentNode != nullptr) {
            Node* temp = currentNode;
            currentNode = currentNode->previousNode;
            delete temp;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
