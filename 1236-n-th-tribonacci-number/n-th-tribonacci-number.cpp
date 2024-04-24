class Solution {
public:
    int tribonacci(int n) {
        int a1 = 0, a2 = 1, a3 = 1;
        int count = 3;
        if(n == 0)  return 0;
        if(n == 1 || n == 2)    return 1;
        for(int i = 2; i <= n; i++)
        {
            int num = a1 + a2 + a3;
            if(count == n)  return num;
            a1 = a2;
            a2 = a3;
            a3 = num;
            count++;
        }
        return -1;
    }
};