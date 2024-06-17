class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int left = 0, right = sqrt(c);
        while(left <= right)
        {
            long long r = pow(left, 2) + pow(right, 2);
            if(r == c)  return true;
            if(r > c) {
                right--;
            }
            else {
                left++;
            }
        }
        return false;
    }
};