class Solution {
public:

    map<string, string> mp;
    long int num = 10000;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        int n = longUrl.size();
        string tinyurl = "http://tinyurl.com/"+to_string(num) + "X";
        num++;
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