class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 1)  return 0;
        // a=arr[i] ^ arr[i+1] ^ ... ^ arr[j-1]
        // b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
        // Note i < j <= k 
        // a==b <=> a^b==0 

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int xor_sum = 0;    //variable instead of an array
            // xor(arr[i...k])
            for(int k = i; k < n; k++) {
                xor_sum = xor_sum ^ arr[k];
                // For given i, k there are (k-i) choices for  j
                if(xor_sum == 0)
                    ans += (k - i);
            }
        }
        return ans;
    }
};