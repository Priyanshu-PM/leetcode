class Solution {

public:
    int trap(vector<int>& height) {

        int n = height.size();

        // intuition based algorithm
        // instead of storing the previous greater or next greater for each index
        // simply storing the single leftMax and rightMax
        int count = 0;
        int leftMax = 0, rightMax = 0;
        int l = 0, r = n-1;
        while(l <= r) {
            if(height[l] <= height[r]) {
                if(height[l] >= leftMax)
                    leftMax = height[l];
                else 
                    count += leftMax - height[l];
                l++;
            }
            else {
                if(height[r] >= rightMax)
                    rightMax = height[r];
                else
                    count += rightMax - height[r];
                r--;
            }
        }

        return count;
    }
};