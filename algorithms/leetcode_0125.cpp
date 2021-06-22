/*
125. Valid Palindrome
https://leetcode.com/problems/valid-palindrome/
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size();
        while(left < right) {
            if (!isAlphanumericCharacter(s[left])) {
                ++left;
            }
            else if (!isAlphanumericCharacter(s[right])) {
                --right;
            }
            else if (isNotEqual(s[left], s[right])) {
                return false;
            }
            else {
                ++left;
                --right;
            }
        }
        
        return true;
    }
    
    inline bool isNotEqual(char ch1, char ch2) {
        // return (s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32;
        return tolower(ch1) != tolower(ch2);
    }
    
    bool isAlphanumericCharacter(char ch) {
        if (ch >= 'a' && ch <= 'z') return true;
        if (ch >= 'A' && ch <= 'Z') return true;
        if (ch >= '0' && ch <= '9') return true;
        return false;
    }
};
