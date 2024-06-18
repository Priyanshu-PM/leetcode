class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    
        int n = digits.size();

        // start from the last
        for(int i = n-1; i >= 0; i--) {
            // if it is the last element then simply increment it
            if(i == n-1) {
                digits[i]++;
            }

            // if it becomes 10, then make it 0, and check if the previous digit is not 0, it it is not, then increment it
            if(digits[i] == 10) {
                digits[i] = 0;
                if(i != 0) {
                    digits[i-1]++;
                }
                // if it is first digit, then add the 0 at the end and make the first digit as 1
                else {
                    digits.push_back(0);
                    digits[i] = 1;
                }
            }
        }
        return digits;
    }
};