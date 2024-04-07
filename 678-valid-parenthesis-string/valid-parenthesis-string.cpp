class Solution {
public:
    // bool checkValidString(string s) {
        
    //     // stack<char> st;
    //     // int count = 0;
    //     // for(int i = 0; i < s.length(); i++) {
    //     //     if(s[i] == '*') count++;
    //     //     else if(st.empty()) {
    //     //         st.push(s[i]);
    //     //     }
    //     //     else if(st.to3p() == '(' && s[i] == ')') {
    //     //         st.pop();
    //     //     } else {
    //     //         st.push(s[i]);
    //     //     }
    //     // }
    //     // int count1 = 0;
    //     // while(!st.empty()) {
    //     //     count1++;
    //     //     st.pop();
    //     // }

    //     // return (count >= count1);

    //     int count = 0;
    //     int countStar = 0;
    //     for(char ch: s) {
    //         if(ch == '(') count++;
    //         else if(ch == ')') count--;
    //         else countStar++;
    //     }
    //     count = abs(count);
    //     return (count <= countStar);
    // }

    bool checkValidString(string s) {
        int curr=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='('||s[i]=='*') {
                curr++;
            }
            else {
                curr--;
            }
            if(curr<0) {
                return false;
            }
        }
        curr=0;
        for(int i=s.size()-1;i>=0;i--) {
            if(s[i]==')'||s[i]=='*') {
                curr++;
            }
            else {
                curr--;
            }
            if(curr<0){
                return false;
            }
        }
        return true;
    }
};