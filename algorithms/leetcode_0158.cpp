/*
158. Read N Characters Given Read4 II - Call multiple times
https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) {
            if (readPos == writePos) {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0) {
					return i;
				}
            }
            buf[i] = buff[readPos++];
        }
        return n;
    }
private:
    int readPos = 0;
	int writePos = 0;
    char buff[4];
};
