/*
https://leetcode.com/problems/spiral-matrix/
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};

        auto const rlen = matrix.size();
        auto const clen = matrix.at(0).size();
        vector<vector<bool>> seen(rlen, vector<bool>(clen, false));

        vector<int> ans;

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        int r = 0, c = 0, di = 0;

        for (auto i = 0; i < (rlen * clen); ++i){
            ans.emplace_back(matrix[r][c]);
            seen[r][c] = true;
            auto const cr = r + dr[di];
            auto const cc = c + dc[di];
            if (0 <= cr && cr < rlen && 0 <= cc && cc < clen && !seen[cr][cc]) {
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
