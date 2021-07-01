/*
140. Word Break II
https://leetcode.com/problems/word-break-ii/
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) { 
        unordered_map<string, vector<string>> m;
        return helper(s, wordDict, m);
    }
    
    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& m) {
        if (m.count(s)) {
            return m[s];
        }
        
        if (s.empty()) {
            return {""};
        }
        
        vector<string> r;
        
        for (string word : wordDict) {
            if (s.substr(0, word.size()) != word) {
                continue;
            }
            auto strs = helper(s.substr(word.size()), wordDict, m);
            for (auto str : strs) {
                r.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        
        m[s] = r;
        
        return m[s];
    }
};

