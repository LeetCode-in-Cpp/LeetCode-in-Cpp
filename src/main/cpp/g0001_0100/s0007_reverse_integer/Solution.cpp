// #Medium #Top_Interview_Questions #Math #Udemy_Integers
// #2024_05_23_Time_0_ms_(100.00%)_Space_7.5_MB_(52.06%)

class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while (x != 0) {
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }
        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
        return static_cast<int>(rev);
    }
};
