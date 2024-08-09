class Solution {
private:
    bool isMagicGrid(vector<vector<int>>& grid, int startRow, int startCol)
    {
        vector<int> rowSum(3, 0), colSum(3, 0);
        int leftDiagonal = 0, rightDiagonal = 0;
        vector<int> hash(10, 0);

        for(int i = startRow; i < startRow + 3; i++)
        {
            for(int j = startCol; j < startCol + 3; j++)
            {
                if(grid[i][j] < 10) hash[grid[i][j]]++;

                if(i - startRow == j - startCol)
                    leftDiagonal += grid[i][j];

                if((i - startRow) + (j - startCol) == 2)
                    rightDiagonal += grid[i][j];

                rowSum[i - startRow] += grid[i][j];
                colSum[j - startCol] += grid[i][j];
            }
        }
        
        for(int i = 1; i < 10; i++) {
            if(!hash[i])    return false;
        }
        
        if(rowSum[0] == rowSum[1] && rowSum[1] == rowSum[2] && rowSum[0] == colSum[0] 
        && colSum[0] == colSum[1] && colSum[1] == colSum[2] 
        && colSum[1] == leftDiagonal && leftDiagonal == rightDiagonal)    
            return true;
        
        return false;

    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        
        for(int i = 0; i <= n - 3; i++)
        {
            for(int j = 0; j <= m - 3; j++)
            {
                if(isMagicGrid(grid, i, j)) count++;
            }
        }

        return count;
    }
};