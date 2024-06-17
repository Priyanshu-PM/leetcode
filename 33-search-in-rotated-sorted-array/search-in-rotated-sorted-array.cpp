class Solution {
public:
    int findMin(vector<int>& nums){
        
        int n = nums.size(), start = 0, end = n - 1;
        int mid = start + (end-start)/2;
        while(start < end) {

            if(nums[0] <= nums[mid]) {

                start = mid + 1;
            }
            else {
                end = mid;
            }
            mid = start + (end-start)/2;
        }
        return start;
    }
    
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target) 
                return mid;
            
            else if(target > nums[mid]) 
                start = mid + 1;
            
            else 
                end = mid - 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target){
        int n = nums.size(), minPos = findMin(nums);
        
        if(binarySearch(nums, target, 0, minPos - 1) != -1) {
            
            return binarySearch(nums, target, 0, minPos - 1);
        }
        return binarySearch(nums, target, minPos, n - 1);
    }
};