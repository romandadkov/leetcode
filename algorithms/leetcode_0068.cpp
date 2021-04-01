/*
68. Text Justification
https://leetcode.com/problems/text-justification/
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int first_word = 0, line_len = 0;
        for (int i = 0; i < words.size(); ++i) {
            const int word_len = words[i].size(); // len of the word
            const int min_spaces_len = (i - first_word);  // min count (len) of spaces
            if (line_len + word_len + min_spaces_len > maxWidth) {
                res.push_back(compose_line(words, maxWidth, first_word, i, line_len, false));
                first_word = i;
                line_len = 0;
            }
            line_len += word_len;
        }
        // last line
        res.push_back(compose_line(words, maxWidth, first_word, words.size(), line_len, true));
        return res;
    }
    
    string compose_line(const vector<string>& words, int maxWidth, int begin, int end, int len, bool alignment = true) {
        string res;
        const int n = end - begin;
        for (int i = 0; i < n; ++i) {
            res += words[begin + i];
            add_spaces(i, n - 1, maxWidth - len, alignment, res);
        }
        // one word line case
        if (res.size() < maxWidth) {
            res.append(maxWidth - res.size(), ' ');
        }
        return res;
    }
    
    void add_spaces(int i, int space_cnt, int maxWidth, bool is_last, string &s) {
        if (i < space_cnt) {
            // for the last line of text, it should be left justified,
            // and no extra space is inserted between words.
            int spaces = is_last ? 1 : maxWidth / space_cnt + (i < maxWidth % space_cnt);
            s.append(spaces, ' ');
        }
    }
};
