// Unorderedmap and set 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        unordered_map<int,int> um;
        for(int i:nums)
            us.insert(i);
        
        int lc=0;
        for(int i:nums){
            int c=i;
            while(us.find(c)!=us.end())
                us.erase(c++);
            if(um.find(c)!=um.end())
                c=c+um[c];
            um[i]=(c-i);
            if((c-i)>lc)
                lc=c-i;
        }
        return lc;         
    }
};