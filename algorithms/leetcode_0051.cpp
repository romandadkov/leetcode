/*
51. N-Queens
https://leetcode.com/problems/n-queens/
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        num = n;
        cols = vector<int>(n, 0);
        hill_diagonals = vector<int>(4 * n - 1, 0);
        dale_diagonals = vector<int>(2 * n - 1, 0);
        queens = vector<string>(n, string(n, '.'));
        backtrack();
        
        return output;
    }
    
    void backtrack(int row = 0) {
        for (int col = 0; col < num; ++col) {
            if (could_place(row, col)) {
                place_queen(row, col);
                if (row + 1 == num) {
                    output.push_back(queens);
                }
                else {
                    backtrack(row + 1);
                }
                remove_queen(row, col);
            }
        }
    }
    
    bool could_place(int row, int col) {
        return ((cols[col] + hill_diagonals[row - col + 2 * num] + dale_diagonals[row + col]) == 0);
    }
    
    void place_queen(int row, int col) {
        queens[row][col] = 'Q';
        cols[col] = 1;
        hill_diagonals[row - col + 2 * num] = 1;
        dale_diagonals[row + col] = 1;
    }
    
    void remove_queen(int row, int col) {
        queens[row][col] = '.';
        cols[col] = 0;
        hill_diagonals[row - col + 2 * num] = 0;
        dale_diagonals[row + col] = 0;
    }
    
    
private:
    vector<int> cols;
    // For all "hill" diagonals row + column = const, and for all "dale" diagonals row - column = const.
    vector<int> hill_diagonals;
    vector<int> dale_diagonals;
    
    vector<string> queens;
    vector<vector<string>> output;
    
    int num;
};

//  https://www.youtube.com/watch?v=DYz2A9s0IQ4 - additional info 
