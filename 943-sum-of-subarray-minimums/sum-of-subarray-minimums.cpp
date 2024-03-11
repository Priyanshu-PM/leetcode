#include <bits/stdc++.h>
class Solution {
public:
    const int mod = (int)(1e9+7);
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        stack<int> s1, s2;
        vector<int> nextSmaller(n), prevSmaller(n);

        for(int i = 0; i < n; i++) {
            nextSmaller[i] = n - i - 1;
            prevSmaller[i] = i;
        }

        // finding the index of the previous smaller element for the current element
        for(int i = 0; i < n; i++) {

            while(!s1.empty() && arr[s1.top()] > arr[i]) {

                nextSmaller[s1.top()] = i - s1.top() - 1;
                s1.pop();
            }

            s1.push(i);
        }

        // finding the index of the next smaller element for the current element
        for(int i = n-1; i >= 0; i--) {
            while(!s2.empty() && arr[s2.top()] >= arr[i]) {
                
                prevSmaller[s2.top()] = s2.top() - i - 1;
                s2.pop();
            }

            s2.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {

            long long temp = (prevSmaller[i] + 1) * (nextSmaller[i] + 1);
            ans += (arr[i] * temp);
            ans %= mod;
        }

        return (int)ans;
    }
};