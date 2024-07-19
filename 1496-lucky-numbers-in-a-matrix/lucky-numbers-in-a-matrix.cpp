class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> minEle(n, INT_MAX);
        vector<int> maxEle(m, INT_MIN);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                minEle[i] = min(minEle[i], matrix[i][j]);
                maxEle[j] = max(maxEle[j], matrix[i][j]);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int el = matrix[i][j];
                if(el == minEle[i] && el == maxEle[j])  return {el};
            }
        }
        return {};
    }
};