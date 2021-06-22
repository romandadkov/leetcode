/*
126. Word Ladder II
https://leetcode.com/problems/word-ladder-ii/
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> r;
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);
        int level = 1, minLevel = numeric_limits<int>::max();
        unordered_set<string> words;
        while(!paths.empty()) {
            auto t = paths.front(); paths.pop();
            if (t.size() > level) {
                for (string w : words) {
                    wordSet.erase(w);
                }
                words.clear();
                level = t.size();
                if (level > minLevel) {
                    break;
                }
            }
            
            string last = t.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (!wordSet.count(newLast)) {
                        continue;
                    }
                    words.insert(newLast);
                    vector<string> nextPath = t;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        r.push_back(nextPath);
                        minLevel = level;
                    }
                    else {
                        paths.push(nextPath);
                    }
                }
            }
        }
        
        return r;
    }
};
