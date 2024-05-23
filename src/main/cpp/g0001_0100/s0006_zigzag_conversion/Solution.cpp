// #Medium #String #2024_05_23_Time_3_ms_(97.69%)_Space_10_MB_(97.13%)

#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        int sLen = s.length();
        if (numRows == 1) {
            return s;
        }
        int maxDist = numRows * 2 - 2;
        std::string buf;
        buf.reserve(sLen);
        for (int i = 0; i < numRows; i++) {
            int index = i;
            if (i == 0 || i == numRows - 1) {
                while (index < sLen) {
                    buf += s[index];
                    index += maxDist;
                }
            } else {
                while (index < sLen) {
                    buf += s[index];
                    index += maxDist - i * 2;
                    if (index >= sLen) {
                        break;
                    }
                    buf += s[index];
                    index += i * 2;
                }
            }
        }
        return buf;
    }
};
