class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.size();
        int nlen = needle.size();
        int nIndex = 0;
        for(int i = 0; i < hlen; i++)
        {
            if(haystack[i] == needle[nIndex])   nIndex++;
            else
            {
                i = i - nIndex;
                nIndex = 0;
            }
            if(nIndex == nlen)  return i - nlen + 1;
        }
        return -1;
    }
};