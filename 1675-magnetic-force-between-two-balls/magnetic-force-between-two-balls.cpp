class Solution {
private:
    bool check(vector<int>& position, int m, int mid)
    {
        int lowest = position[0], cnt = 1;
        for(int i = 1; i < position.size(); i++)
        {
            if((position[i] - lowest) >= mid) {
                ++cnt;
                if(cnt == m)    return true;
                lowest = position[i];
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        
        long long low = 1;
        long long high = *max_element(position.begin(), position.end());
        sort(position.begin(), position.end());
        int ans = 0;
        while(low <= high)
        {
            long long mid = (low + high)/2;
            if(check(position, m, mid)) {
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};