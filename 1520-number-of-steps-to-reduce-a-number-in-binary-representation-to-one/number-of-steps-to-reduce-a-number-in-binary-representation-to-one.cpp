class Solution {
public:
    int numSteps(string s) {
        
        int count = 0;
        int carry = 0;

        for(int i = s.size()-1; i >= 1; i--) {
            int num = s[i] - '0';
            if(num == 0 && carry == 0) {
                count++;
            }
            else if(num == 1 && carry == 1) {
                count++;
                carry = 1;
            }
            else {
                count += 2;
                carry = 1;
            }
        }
        if(carry == 1)  count++;
        return count;
    }
};