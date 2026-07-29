class MinStack {
public:
    stack<int> minSt;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty())
        {
            minSt.push(val);
        }
        else
        {
            if (minSt.top() >= val)
            {
                minSt.push(val);
            }
        }
    }
    
    void pop() {
        if (!st.empty())
        {
            if (!minSt.empty() && st.top() == minSt.top())
            {
                minSt.pop();
            }
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if (!minSt.empty())
        {
            return minSt.top();
        }
        else
        {
            return st.top();
        }
    }
};
