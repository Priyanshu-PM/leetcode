class Solution {

private:
    bool isPossibleSolution(vector<int>& bloomDay, int m, int k, int mid) {

        int countFlowers = 0;
        int countBouquets = 0;
        
        for(int i = 0; i < bloomDay.size(); i++) 
        {
            if(bloomDay[i] <= mid) 
            {
                countFlowers++;
                if(countFlowers == k) 
                {
                    countBouquets += 1;
                    countFlowers = 0;
                }
            }
            else 
            {
                countFlowers = 0;
            }
        }
        
        return countBouquets >= m;

    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int minDays = INT_MAX;
        while(low <= high) {
            int mid = (low + high)/2;
            if(isPossibleSolution(bloomDay, m, k, mid)) {   
                minDays = min(minDays, mid);
                high = mid - 1;
            }
            else {
                low = mid+1;
            }
        }
        return minDays = (minDays != INT_MAX) ? minDays : -1;
    }
};