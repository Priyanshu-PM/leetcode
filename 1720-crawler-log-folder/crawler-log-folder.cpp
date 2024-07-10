class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int cnt = 0;
        for(string op: logs) {
            if(op == "../") {
                if(cnt > 0) cnt--;
            }
            else if(op == "./")
            {}
            else {
                cnt++;
            }
        }
        return cnt;
    }
};