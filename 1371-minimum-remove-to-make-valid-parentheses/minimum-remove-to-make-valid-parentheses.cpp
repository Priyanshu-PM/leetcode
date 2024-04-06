class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        vector<char> arr(s.begin(), s.end());
        int openParenthesis = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == '(') openParenthesis++;
            else if(arr[i] == ')')
            {
                if(openParenthesis == 0)
                    arr[i] = '*';
                else
                    openParenthesis--;
            }
        }
        for(int i = arr.size()-1; i >= 0; i--)
        {
            if(openParenthesis > 0 && arr[i] == '(') {
                arr[i] = '*';
                openParenthesis--;
            }
        }

        string result = "";
        for(char c: arr)
            if(c != '*')
                result += c;
            
        return result;
    }
};