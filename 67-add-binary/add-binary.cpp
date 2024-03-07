class Solution {
public:
    string addBinary(string a, string b) {
        string answer = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while( i >= 0 || j >= 0) {
            
            int sum = carry;
            if(i >= 0)
                sum += a[i--] - '0';
            if(j >= 0)
                sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            answer += to_string(sum%2);
        }
        if(carry) {
            answer += to_string(carry);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};