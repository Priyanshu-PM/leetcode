class Solution {
private:
    int count(vector<int>& nums, int target)
    {
        int ans = 0;
        for(int ele: nums) {
            if(ele >= target)   ans++;
        }
        return ans;
    }
public:
    int specialArray(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();

        while(left <= right) {
            int mid = (left + right)/2;
            int ans = count(nums, mid);

            if(ans == mid)  return mid;
            else if(ans > mid)  left = mid + 1;
            else    right = mid - 1;
        }
        return -1;
    }
};