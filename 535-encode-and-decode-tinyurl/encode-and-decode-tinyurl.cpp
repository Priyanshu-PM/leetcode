class Solution {
public:

    map<string, string> mp;

    string gen_random(int len) {
        static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        string tmp_s;

        for (int i = 0; i < len; ++i) {
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
        }
        
        return tmp_s;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        int n = longUrl.size();
        string tinyurl = "http://tinyurl.com/"+gen_random(8);
        mp[tinyurl] = longUrl;
        return tinyurl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));