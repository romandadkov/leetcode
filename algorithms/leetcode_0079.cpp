/*
79. Word Search
https://leetcode.com/problems/word-search/
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return false;
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (check(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool check(vector<vector<char>>& board, string word, int i, int j, int p) {
        if (p == word.size()) {
            return true;
        }
        
        if (i < 0 ||
            i >= board.size() ||
            j < 0 ||
            j >= board[i].size()) {
            return false;
        }
        
        char c = board[i][j];
        if (c == word[p]) {
            board[i][j] = '#';
            
            if (check(board, word, i - 1, j, p + 1)) return true;
            if (check(board, word, i + 1, j, p + 1)) return true;
            if (check(board, word, i, j - 1, p + 1)) return true;
            if (check(board, word, i, j + 1, p + 1)) return true;
            
            board[i][j] = c;
        }
        
        return false;
    }
};
