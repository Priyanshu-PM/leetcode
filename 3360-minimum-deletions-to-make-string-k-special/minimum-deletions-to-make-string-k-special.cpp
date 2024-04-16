class Solution {
private:
    int solve(int index, vector<int>& mp, vector<int>& vis, int k)
    {
        int mini = 1e8;
        for(int i = 0; i < 26; i++)
        {
            if(vis[i] == 1 || i == index) continue;
            if(mp[i] > 0)
            {
                int diff = abs(mp[index] - mp[i]);
                vis[i] = 1;
                if(diff > k)
                {
                    mini = min(mini, min(diff - k, mp[index]) + solve(i, mp, vis, k));
                }
                else
                    mini = min(mini, 0 + solve(i, mp, vis, k));
                vis[i] = 0;
            }
        }
        return mini == 1e8 ? 0 : mini;
    }
public:
    int minimumDeletions(string word, int k) {
        
        //  frequency count
//         vector<int> mp(26, 0);
//         for(char c: word)   mp[c - 'a']++;
        
//         int mini = INT_MAX;
//         for(int i = 0; i < 26; i++)
//         {
//             vector<int> vis(26, 0);
//             if(mp[i] > 0)
//             {
//                 vis[i] = 1;
//                 int temp = solve(i, mp, vis, k);
//                 mini = min(mini, temp);
//             }
//         }
//         return mini;
        
        unordered_map<char, int> mp;
        for(char ch: word)  mp[ch]++;

        vector<int> count;

        for(auto it: mp)
        {
            count.push_back(it.second);
        }

        sort(count.begin(), count.end(),  greater<int>());
        int mini = INT_MAX;
        
        for(int i = 0; i < count.size(); i++)
        {
            int t = count[i], del = 0;
            for(int d: count)
            {
                if(d > t + k)
                {
                    del += d - (t + k);
                }
                else if(d < t)
                    del += d;
            }
            
            mini = min(mini, del);
            if(mini == 0)   break;
        }
        
        return mini == INT_MAX ? 0 : mini;
    }
};