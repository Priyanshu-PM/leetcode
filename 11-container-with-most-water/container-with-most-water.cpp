class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;
        int maxarea = 0;
        while(left <= right) {
            
            int h = min(height[left], height[right]);
            int l = right - left;
            int area = h*l;
            
            maxarea = max(maxarea, area);
            if(height[left] < height[right]) {
                left++;
            }
            else if(height[right] < height[left]) {
                right--;
            }
            else {
                left++;
                right--;
            }
        }
        return maxarea;
    }
};
