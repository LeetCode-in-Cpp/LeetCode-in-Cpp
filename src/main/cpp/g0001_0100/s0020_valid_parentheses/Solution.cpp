// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #String #Stack
// #Data_Structure_I_Day_9_Stack_Queue #Udemy_Strings #Big_O_Time_O(n)_Space_O(n)
// #2024_05_23_Time_0_ms_(100.00%)_Space_7.6_MB_(59.50%)

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else if (c == ')' && !stack.empty() && stack.top() == '(') {
                stack.pop();
            } else if (c == '}' && !stack.empty() && stack.top() == '{') {
                stack.pop();
            } else if (c == ']' && !stack.empty() && stack.top() == '[') {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
};
