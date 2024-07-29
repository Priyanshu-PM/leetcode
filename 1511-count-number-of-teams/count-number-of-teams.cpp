class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size();
        int ans = 0;
        for(int j = 1; j < n-1; j++)
        {
            int countSmallLeft = 0, countLargeLeft = 0;
            int countSmallRight = 0, countLargeRight = 0;

            for(int i = 0; i < j; i++)
            {
                if(rating[i] < rating[j])   countSmallLeft++;
                else if(rating[i] > rating[j])   countLargeLeft++;
            }

            for(int i = j+1; i < n; i++)
            {
                if(rating[i] < rating[j])   countSmallRight++;
                else if(rating[i] > rating[j])  countLargeRight++;
            }

            ans += (countSmallLeft * countLargeRight);
            ans += (countLargeLeft * countSmallRight);
        }

        return ans;
    }
};