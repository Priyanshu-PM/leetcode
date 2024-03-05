class Solution {
public:
    int minimumLength(string s) {
        
        int n = s.size();
        if(n == 1)  return 1;
        // cout << "n = " << n << "\n";
        int i = 0, j = n-1;
        int ans = 0;
        while(i <= j)
        {
            if(s[i] == s[j])
            {
                char prev = s[i];
                while(i < n && s[i] == prev) i++;
                while(j >= 0 && s[j] == prev) j--;
                // cout << "i = "<< i << " | j = " << j << "\n";
                if(i == j)  return 1;
            }
            else
            {
                return j - i + 1;
            }
        }
        return 0;
    }
};