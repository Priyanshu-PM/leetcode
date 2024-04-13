class Solution {
private:
    void fun(vector<int>& v, int num) {
    int i = 0;
    while (num > 0) {
        int rem = num % 2;
        if (rem == 1) {
            v[i] += 1;
        }
        num = num / 2;
        i++;
    }
}

void fun1(vector<int>& v, int num) {
    int i = 0;
    while (num > 0) {
        int rem = num % 2;
        if (rem == 1)
            v[i] -= 1;
        num = num / 2;
        i++;
    }
}

int formnumber(vector<int>& bits) {
    int value = 0;
    int ans = 1;
    for(int i = 0; i < 30; i++)
    {
        if(bits[i] >= 1)
            value += ans;
        ans = ans * 2;
    }
    return value;
}

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        vector<int> bits(32, 0);
        int i, j = 0;
        int val = 0;
        int ans = INT_MAX;
        for (i = 0; i < nums.size(); i++) {
            val = val | nums[i];
            fun(bits, nums[i]);
            while (i >= j && val >= k) {
                ans = min(ans, (i - j + 1));
                fun1(bits, nums[j]);
                val = formnumber(bits);
                j++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};