/*
https://leetcode.com/problems/group-anagrams/

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

*/

class Solution {
public:
    string hash(string s) {
        sort(begin(s), end(s));
        return s;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (const auto& str : strs) {
            m[hash(str)].push_back(str);
        }
        vector<vector<string>> answ;
        for (const auto& p : m) {
            answ.push_back(p.second);
        }
        return answ;
    }
};
