/*
59. Spiral Matrix II
https://leetcode.com/problems/spiral-matrix-ii/
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        auto const rlen = n;
        auto const clen = n;
        vector<vector<int>> ans(rlen, vector<int>(clen, 0));
        
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        
        int r = 0, c = 0, di = 0;
        
        for (auto i = 1; i <= (rlen * clen); ++i){
            ans[r][c] = i;
            auto const cr = r + dr[di];
            auto const cc = c + dc[di];
            if (0 <= cr && cr < rlen && 0 <= cc && cc < clen && ans[cr][cc] == 0) {
               r = cr;
               c = cc;
            }
            else {
                di = (di + 1) % 4;
                r = r + dr[di];
                c = c + dc[di];  
            }
        }
        
        return ans;
    }
};
