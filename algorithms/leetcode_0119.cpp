/*
119. Pascal's Triangle II
https://leetcode.com/problems/pascals-triangle-ii/
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> r(2, vector<int>());
        for (int k = 0; k <= rowIndex; ++k) {
            const int idx = k % 2;
            const int j = (k - 1) % 2;
            r[idx].resize(k + 1, 1);
            for (int i = 1; i < k; ++i) {
                r[idx][i] = r[j][i - 1] + r[j][i];
            }    
        }
        
        return r[rowIndex % 2];
    }
};
