class Solution {
public:
    int findComplement(int num) {
        
        int ans = 0;
        int i = 0;
        while(num > 0)
        {
            if(num & 1) {
                ans = ans | (0 << i);
            }
            else {
                ans = ans | (1 << i);
            }
            num = num >> 1;
            i++;
        }
        return ans;
    }
};