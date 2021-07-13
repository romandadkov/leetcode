/*
151. Reverse Words in a String
https://leetcode.com/problems/reverse-words-in-a-string/
*/
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        istream_iterator<string> beg(ss);
        istream_iterator<string> end;
        vector<string> v(beg, end);
        return accumulate(
            std::next(rbegin(v)), rend(v), v.back(), 
            [](string a, string b) { return a + " " + b;});
    }
};
