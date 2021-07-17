/*
157. Read N Characters Given Read4
https://leetcode.com/problems/read-n-characters-given-read4/
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int res = 0;
        for (int i = 0; i <= n / 4; ++i) {
            const int cur = read4(buf + res);
            if (cur == 0) {
				break;
			}
            res += cur;
        }
        return min(res, n);
    }
};
