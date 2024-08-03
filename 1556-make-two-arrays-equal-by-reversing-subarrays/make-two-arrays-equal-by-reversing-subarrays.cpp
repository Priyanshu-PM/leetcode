class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        unordered_map<int,int> mp;
        for(int e: arr) mp[e]++;
        for(int e: target)  {
            if(mp.find(e) == mp.end())  return false;
            mp[e]--;
            if(mp[e] == 0)  mp.erase(e);
        }

        return (mp.size() == 0);
    }
};