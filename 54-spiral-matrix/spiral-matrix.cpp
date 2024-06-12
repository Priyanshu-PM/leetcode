class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        
        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0, totalElements = row * col;

        int startingRow = 0, startingCol = 0;
        int endingRow = row - 1, endingCol = col - 1;

        while(count < totalElements) {

            for(int i = startingCol; count < totalElements && i <= endingCol; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            for(int i = startingRow; count < totalElements &&  i <= endingRow; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            for(int i = endingCol; count < totalElements &&  i >= startingCol; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            for(int i = endingRow; count < totalElements &&  i >= startingRow; i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans;
    }
};