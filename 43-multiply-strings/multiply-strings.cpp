class Solution {
public:
    string multiply(string& A, string& B) {
        if(A == "0" || B == "0") return "0";          
		if(size(A) < size(B)) return multiply (B, A);
        string ans = "";
        for(int j = size(B)-1, spaces = 0; j >= 0; j--) {
            auto res = multiplyDigit(A, B[j], spaces++);    
            ans = addStrings(ans, res);      
        }
        return ans;
    }
private:

    string multiplyDigit(string& s, char c, int spaces) {
        int i = size(s)-1, carry = 0, digit1 = c-'0', digit2, res;

        string ans = string(spaces, '0');
        while(i >= 0) {
            digit2 = s[i--]-'0';            
            res = digit1 * digit2 + carry;         
            carry = res / 10;               
            ans += res%10+'0';        
        }
        if(carry) ans += carry+'0';                
        reverse(begin(ans), end(ans));        
        return ans;
    }
	
    string addStrings(string& A, string& B) {
        if(size(A) < size(B)) return addStrings(B, A); 
        int i = size(A)-1, j = size(B)-1, carry = 0, digit1, digit2, res;
        string ans = "";
        while(i >= 0) {
            digit1 = A[i--]-'0', digit2 = j >= 0 ? (B[j--]-'0') : 0; 
            res = digit1 + digit2 + carry;               
            carry = res / 10;                          
            ans += res%10+'0';                          
        }
        if(carry) ans += carry+'0';                      
        reverse(begin(ans), end(ans));           
        return ans;
    }
};