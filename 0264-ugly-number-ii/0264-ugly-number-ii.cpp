class Solution {
public:
     
    int nthUglyNumber(int n) {
        unordered_set<long long> st;
        priority_queue<long long, vector<long long>, 
                greater<long long>> pq;
        pq.push(1); 
               
        /*
        1   set : [1] pq : [2, 3, 5]
        2   set : [1, 2] pq : [3, 4, 5, 6, 10]
        3   set : [1, 2, 3] pq : [4, 5, 6, 9, 10, 15] 
    
        */
        int cnt = 0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (st.count(cur)) continue;
            st.insert(cur);
            
            ++cnt;
            if (cnt == n) return cur;
            
            if (!st.count(cur*2)) pq.push(cur*2);
            if (!st.count(cur*3)) pq.push(cur*3);
            if (!st.count(cur*5)) pq.push(cur*5);
        }
        return -1;
        
    }
};