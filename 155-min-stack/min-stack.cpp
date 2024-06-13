class MinStack {
public:
    stack<int> st;
    vector<int> vec;
    int n = 0, m = 0;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(n != 0) {
            val = min(val, vec[n-1]);
        }
        if(m == n) {
            vec.push_back(val);
            m += 1;
        }
        else {
            vec[n] = val;
        }
        n++;
    }
    
    void pop() {
        st.pop();
        n = n-1;
    }
    
    int top() {
        if(!st.empty()) return st.top();
        return -1;
    }
    
    int getMin() {
        return vec[n-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */