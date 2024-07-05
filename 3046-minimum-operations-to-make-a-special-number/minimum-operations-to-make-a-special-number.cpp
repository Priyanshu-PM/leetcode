class Solution {
public:
    int minimumOperations(string num) {
        
        int n = num.size();
        vector<int> zero, two, five, seven;
        for(int i = 0; i < n; i++)
        {
            if(num[i] == '0')   zero.push_back(i);
            else if(num[i] == '2')  two.push_back(i);
            else if(num[i] == '5')  five.push_back(i);
            else if(num[i] == '7')  seven.push_back(i);
        }

        int ans = INT_MAX;
        for(int i = zero.size()-1; i >= 0; i--)
        {
            for(int j = i-1; j >= 0; j--)
            {
                int temp = (zero[i] - zero[j] - 1) + (n - zero[i] - 1);
                ans = min(ans, temp);
            }
            for(int j = five.size()-1; j >= 0; j--)
            {
                if(five[j] < zero[i]) {
                    int temp = (zero[i] - five[j] - 1) + (n - zero[i] - 1);
                    ans = min(ans, temp);
                }
            }
        }

        for(int i = five.size()-1; i >= 0; i--)
        {
            for(int j = two.size()-1; j >= 0; j--)
            {
                if(five[i] > two[j]) {
                    int temp = (five[i] - two[j] - 1) + (n - five[i] - 1);
                    ans = min(ans, temp);
                }
            }
            for(int j = seven.size()-1; j >= 0; j--)
            {
                if(five[i] > seven[j]) {
                    int temp = (five[i] - seven[j] - 1) + (n - five[i] - 1);
                    ans = min(ans, temp);
                }
            }
        }

        if(ans == INT_MAX)
        {
            return n - zero.size();
        }
        return ans;
    }
};