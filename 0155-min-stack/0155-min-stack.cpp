class MinStack {
public:
    
    /*
    -2  0 -3
    -2 -2 -3
    */
    
    vector<pair<int, int>> st;
    int curMinV;
    
    MinStack() {
        curMinV = INT_MAX;
    }
    
    void push(int val) {
        curMinV = min(curMinV, val);
        st.push_back({val, curMinV});
        
        // int cnt = 0;
        // for (auto & [val, min] : st) {
        //     cout << cnt++ << "/" << val << " (" << min << ")" << " ";
        // }
        // cout << endl;
    }
    
    void pop() {
        // cout << "pop " << endl;
        st.pop_back();
        if (st.empty()) curMinV = INT_MAX;
        else curMinV = st.back().second;
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
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