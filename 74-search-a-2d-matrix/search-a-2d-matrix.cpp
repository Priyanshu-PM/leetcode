class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int i = matrix.size();
        int j = matrix[0].size();

        int left = 0, right = i * j - 1;
        while(left <= right) {
            
            int mid = left + (right - left)/2;
            int mid_val = matrix[mid / j][mid % j];

            if(mid_val == target) {
                return true;
            }
            else if(target > mid_val) {
                left = mid + 1;
            }
            else if(target < mid_val) {
                right = mid - 1;
            }
        }
        return false;
    }
};