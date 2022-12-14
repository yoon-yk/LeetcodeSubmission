class MinStack {
public:
    
    /*
    -2  0 -3
    -2 -2 -3
    */
    
    vector<int> st;
    vector<pair<int, int>> minSt;
    
    MinStack() {
    }
    
    void push(int val) {
        if (minSt.empty() || minSt.back().first > val)
            minSt.push_back({val, 1});
        else if (minSt.back().first == val)
            minSt.back().second++;
        st.push_back(val);
    }
    
    void pop() {
        if (minSt.back().first == st.back()) {
            if (minSt.back().second == 1)
                minSt.pop_back();
            else minSt.back().second--;
        }
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.back().first;
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