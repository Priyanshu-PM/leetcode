class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> temp = board;
        
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int curr = board[i][j];
                int alive = 0, dead = 0;
                for(int k = 0; k < 8; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m)
                    {
                        if(board[nr][nc] == 1)  alive++;
                        else    dead++;
                    }
                }
                if(curr == 1) {
                    if(alive < 2)   temp[i][j] = 0;
                    else if(alive > 3)  temp[i][j] = 0;
                }
                else {
                    if(alive == 3)
                        temp[i][j] = 1;
                }
            }
        }
        board = temp;
    }
};