/*
118. Pascal's Triangle
https://leetcode.com/problems/pascals-triangle/
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return {};
        }
        
        vector<vector<int>> r(numRows, vector<int>());
        
        for(int k = 0; k < numRows; ++k) {
            r[k].resize(k + 1, 1);
            for (int i = 1; i < k; ++i) {
                r[k][i] = r[k - 1][i - 1] + r[k - 1][i];
            }
        }
        
        return r;
    }
};
