/*
https://leetcode.com/problems/length-of-last-word/
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        string word;
        for (stringstream ss {s}; std::getline(ss, word, ' '); ss >> std::ws);
        return word.length();
    }
};
