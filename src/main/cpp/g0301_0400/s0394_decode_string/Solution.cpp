// #Medium #Top_100_Liked_Questions #String #Stack #Recursion #Level_1_Day_14_Stack #Udemy_Strings
// #Big_O_Time_O(n)_Space_O(n) #2024_05_22_Time_0_ms_(100.00%)_Space_7.6_MB_(79.31%)

#include <string>
#include <cctype>
using namespace std;

class Solution {
    private:
    int i = 0;

public:
    string decodeString(const string& s) {
        int count = 0;
        string result;
        while (i < s.length()) {
            char c = s[i];
            ++i;
            if (isalpha(c)) {
                result += c;
            } else if (isdigit(c)) {
                count = count * 10 + (c - '0');
            } else if (c == ']') {
                break;
            } else if (c == '[') {
                // sub problem
                string repeat = decodeString(s);
                while (count > 0) {
                    result += repeat;
                    --count;
                }
            }
        }
        return result;
    }
};
