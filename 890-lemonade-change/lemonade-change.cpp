class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int a5 = 0, a10 = 0;
        for(int i = 0; i < bills.size(); i++)
        {
            if(bills[i] == 5)    a5++;
            
            else if(bills[i] == 10)
            {
                if(a5 > 0)
                {
                    a5--; a10++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(a10 > 0 && a5 > 0)
                {
                    a10--; a5--;
                }
                else if(a5 > 2)
                {
                    a5 -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};