class Solution {
private:
    bool isOperator(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    int getNum(string str)
    {
        int result = 0;
        for(char c: str)
            result = (result * 10) + (c - '0');

        return result;
    }

    int getResult(int num1, int num2, char c)
    {
        switch(c)
        {
            case '+':   return num2 + num1;
            case '-':   return num2 - num1;
            case '*':   return num2 * num1;
            case '/':   return num2 / num1;
        }
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        for(string str: tokens)
        {
            if(str.size() == 1)
            {
                if(isOperator(str[0]))
                {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();

                    int result = getResult(num1, num2, str[0]);
                    st.push(result);
                }
                else
                {
                    int num = getNum(str);
                    st.push(num);
                }
            }
            else
            {
                int num = getNum(str);
                if(isOperator(str[0]))
                {
                    num = getNum(str.substr(1, str.size()));
                    if(str[0] == '-')
                        num = num*(-1);
                }
                st.push(num);
            }
        }   
        return st.top(); 
    }
};