class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while(num != 0) {
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        
        int n = nums.size();

        map<int, priority_queue<int>> mp;

        for(int i = 0; i < n; i++) {

            int sum = getDigitSum(nums[i]);
            mp[sum].push(nums[i]);

        }

        int maxi = -1;

        for(auto it: mp) {
            if(it.second.size() > 1) {

                int temp = 0;

                priority_queue<int> pq = it.second;
                temp += pq.top();
                pq.pop();
                temp += pq.top();

                maxi = max(maxi, temp);
            }
        }
        return maxi;
    }
};