class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        
        int daniel = 0, bob = 0;
        int zeros = 0, ones = 0;
        int miniLevel = INT_MAX;
        for(auto it: possible)
        {
            if(it == 0) zeros++;
            else    ones++;
        }
        
        for(int i = 0; i < possible.size()-1; i++)
        {
            if(possible[i] == 0)
            {
                daniel--;
                zeros--;
            }
            else
            {
                daniel++;
                ones--;
            }
            if(daniel > ones - zeros)
                return i+1;
            
        }
        return -1;
    }
};