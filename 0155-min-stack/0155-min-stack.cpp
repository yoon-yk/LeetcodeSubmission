class MinStack {
public:
    
    /*
    -2  0 -3
    -2 -2 -3
    */
    
    vector<int> st;
    vector<int> minSt;
    
    MinStack() {
    }
    
    void push(int val) {
        if (minSt.empty() || minSt.back() >= val)
            minSt.push_back(val);
        st.push_back(val);
        
//         cout << "minSt" << endl;
//         for (auto & m : minSt) cout << m << " ";
//         cout << endl;
        
//         cout << "st" << endl;
//         for (auto & m : st) cout << m << " ";
//         cout << endl;
    }
    
    void pop() {
        if (minSt.back() == st.back()) minSt.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.back();
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