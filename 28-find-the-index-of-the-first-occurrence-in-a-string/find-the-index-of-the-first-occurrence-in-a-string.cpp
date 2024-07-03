class Solution {
public:
    int strStr(string haystack, string needle) {

        int hlen = haystack.size();
        int nLen = needle.size();

        //  KMP algorithm
        vector<int> lps(nLen, 0);
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while(i < nLen)
        {
            if(needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len != 0) {
                    len = lps[len-1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        for(int i = 0; i < nLen; i++)
            cout << i << " -> " << lps[i] << "\n";

        int nIndex = 0;
        i = 0;
        while(i < hlen)
        {
            if(haystack[i] == needle[nIndex]) {  nIndex++; i++;}
            if(nIndex == nLen)  return i - nLen;
            else if(haystack[i] != needle[nIndex])
            {
                if(nIndex != 0)
                    nIndex = lps[nIndex - 1];
                else {
                    i++; 
                }
            }
        }
        return -1;
    }
};