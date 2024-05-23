// #Easy #Math #Udemy_Integers #2024_05_23_Time_0_ms_(100.00%)_Space_8.2_MB_(48.20%)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int rev = 0;
        int localX = x;
        while (localX > 0) {
            if (rev > (INT_MAX - localX % 10) / 10) {
                return false;
            }
            rev = rev * 10 + localX % 10;
            localX /= 10;
        }
        return rev == x;
    }
};
