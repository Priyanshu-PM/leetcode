class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n = grumpy.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {
                ans += customers[i];
            }
        }

        int i = 0, j = 0;
        int maxi = ans;
        while(j < n) {
            while((j - i + 1) > minutes) {
                if(grumpy[i] == 1)    ans -= customers[i];
                i++;
            }
            if(grumpy[j] == 1) {
                ans += customers[j];
            }
            maxi = max(maxi, ans);
            j++;
        }
        return maxi;
    }
};