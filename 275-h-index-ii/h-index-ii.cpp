class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        int low = 0, high = n-1;
        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int len = n - mid;
            if(citations[mid] < len) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return n - low;
    }
};