/*
52. N-Queens II
https://leetcode.com/problems/n-queens-ii/
*/
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        proc(pos, 0, res);
        return res;
    }
    
    void proc(vector<int>& pos, int row, int& res) {
        int n = pos.size();
        if (row == n) {
            ++res;
        }
        
        for (int col = 0; col < n; ++col) {
            if (is_valid(pos, row, col)) {
                pos[row] = col;
                proc(pos, row + 1, res);
                pos[row] = -1;
            }
        } 
    }
    
    bool is_valid(vector<int>& pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
};
