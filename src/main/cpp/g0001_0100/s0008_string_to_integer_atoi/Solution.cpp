// #Medium #Top_Interview_Questions #String #2024_05_23_Time_0_ms_(100.00%)_Space_8.2_MB_(36.95%)

#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string str) {
        if (str.empty()) {
            return 0;
        }
        int i = 0;
        bool negativeSign = false;
        int len = str.length();
        
        while (i < len && str[i] == ' ') {
            i++;
        }
        
        if (i == len) {
            return 0;
        }
        
        if (str[i] == '+') {
            i++;
        } else if (str[i] == '-') {
            i++;
            negativeSign = true;
        }
        
        int num = 0;
        while (i < len && str[i] >= '0' && str[i] <= '9') {
            int tem = str[i] - '0';
            if (negativeSign) {
                tem = -tem;
            }
            
            if (num < INT_MIN / 10 || (num == INT_MIN / 10 && tem < -8)) {
                return INT_MIN;
            } else if (num > INT_MAX / 10 || (num == INT_MAX / 10 && tem > 7)) {
                return INT_MAX;
            } else {
                num = num * 10 + tem;
                i++;
            }
        }
        return num;
    }
};
