class Solution {
public:
    string simplifyPath(string path) {
         
        int n = path.size();
        vector<string> v;
        string temp = "";
        int i = 0;
        while(i < n)
        {
            if(path[i] == '/') {
                i++;
                continue;
            }
            
            while(i < n && path[i] != '/')  temp.push_back(path[i++]);

            if(temp == ".." && !v.empty())  v.pop_back();
            else if(temp != "." && temp != "..")    v.push_back(temp);
            temp.clear();
            i++;
        }

        string ans = "";
        for(auto s: v) {
            ans.push_back('/');
            ans.append(s);
        }

        if(ans.size() == 0) return "/";
        return ans;
    }
};