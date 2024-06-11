class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int maxi = 0;
        for(int i = 0; i < n; i++) 
        {
            int len = n - i;
            if(maxi <= len) maxi = min(len, citations[i]);
            
        }
        return maxi;
    }
};