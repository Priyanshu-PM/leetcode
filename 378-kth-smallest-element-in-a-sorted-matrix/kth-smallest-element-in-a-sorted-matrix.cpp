class Solution {
private:
    bool check(vector<vector<int>>& matrix, int target, int k, int n)
    {
        int i = n-1;
        int j = 0;
        int num = 0;

        while(i >= 0 && j < n)
        {
            if(matrix[i][j] <= target) {
                num += i+1;
                j++;
            }
            else {
                i--;
            }
        }
        return num >= k;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = matrix[0][0], high = matrix[n-1][m-1];

        while(low < high)
        {
            int mid = low + (high - low)/2;
            
            if(check(matrix, mid, k, n)) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
};