class Solution {
private:
    void merge(int start, int mid, int end, vector<int>& nums)
    {
        vector<int> temp;
        int i = start, j = mid + 1;
        while(i <= mid && j <= end)
        {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i++]);
        }
        while(j <= end) {
            temp.push_back(nums[j++]);
        }

        for(int i = 0; i < temp.size(); i++)
        {
            nums[i + start] = temp[i];
        }
    }

    void mergeSort(int start, int end, vector<int>& nums)
    {
        if(start >= end)    return;
        int mid = start + (end - start)/2;

        mergeSort(start, mid, nums);
        mergeSort(mid+1, end, nums);
        merge(start, mid, end, nums);
    }
public:


    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        mergeSort(0, n-1, nums);
        return nums;
    }
};