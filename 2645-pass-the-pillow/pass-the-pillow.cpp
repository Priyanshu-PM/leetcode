class Solution {
public:
    int passThePillow(int n, int time) {
        
        int temp = time;
        int i = 1;
        while(temp)
        {
            for(i; i < n; i++)
            {
                if(temp == 0)   return i;
                temp--;
            }
            for(i; i >= 2; i--)
            {
                if(temp == 0)   return i;
                temp--;
            }
        }
        return 1;
    }
};