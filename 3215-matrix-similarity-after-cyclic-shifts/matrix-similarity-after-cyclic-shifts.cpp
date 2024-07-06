class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        vector<vector<int>> temp = mat;
        int n = temp.size();
        int m = temp[0].size();
        k = k % m;
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0) {
                reverse(temp[i].end() - k, temp[i].end());
                reverse(temp[i].begin(), temp[i].end() - k);
                reverse(temp[i].begin(), temp[i].end());
            }
            else {
                reverse(temp[i].begin(), temp[i].begin() + k);
                reverse(temp[i].begin()+k, temp[i].end());
                reverse(temp[i].begin(), temp[i].end());

            }
            if(temp[i] != mat[i])   return false;
        }

        return true;
    }
};