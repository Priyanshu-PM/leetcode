class Solution {

private:

    bool solve(int row, int col, int index, vector<vector<char>> &board, string word) {
        
        if(index == word.length()) return true;

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || word[index] != board[row][col] || board[row][col] == '!') {
            return false;
        }
        bool ans = false;
        if(word[index] == board[row][col]) {

            board[row][col] = '!';

            bool top = solve(row-1, col, index+1, board, word);

            bool left = solve(row, col-1, index+1, board, word);

            bool right = solve(row, col+1, index+1, board, word);

            bool bottom = solve(row+1, col, index+1, board, word);

            ans = top || left || right || bottom;
        }

        board[row][col] = word[index];

        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        int index = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && solve(i, j, index, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};