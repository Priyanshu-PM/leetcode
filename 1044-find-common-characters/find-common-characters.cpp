class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<int> freq(26, 200);

        for(int i = 0; i < words.size(); i++) 
        {
            vector<int> temp(26, 0);
            for(char c: words[i])   { temp[c - 'a']++; }
            for(int i = 0; i < 26; i++)     { freq[i] = min(freq[i], temp[i]); }
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++) 
        {
            string s;
            s.push_back((char)(i + 97));
            while(freq[i]-- > 0) 
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};