class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string temp = "";
        int i = 0;
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        int counter = 0;
        while(getline(ss, temp, ' ')) 
        {
            counter++;
            if(i < pattern.size()) 
            {
                if(mp.find(pattern[i]) != mp.end() || mp2.find(temp) != mp2.end()) 
                {
                    if(mp[pattern[i]] != temp)
                        return false;
                }
                else {
                    mp[pattern[i]] = temp;
                    mp2[temp] = pattern[i];
                }
            }
            i++;
        }
        if(counter == pattern.size())   return true;
        return false;
    }
};