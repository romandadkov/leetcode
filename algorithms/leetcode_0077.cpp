/*
77. Combinations
https://leetcode.com/problems/combinations/
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        
        vector<int> p(k, 0);
        for (int i = 0; i >= 0;) {
            p[i]++;
            if (p[i] > n) {
                i--;
            }
            else if (i == k - 1) {
                res.push_back(p);
            }
            else {
                i++;
                p[i] = p[i - 1];
                
            }
        }
        
        return res;
    }
};
