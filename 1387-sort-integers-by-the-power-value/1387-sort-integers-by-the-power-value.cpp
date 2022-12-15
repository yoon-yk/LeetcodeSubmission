class Solution {
public:
    int getKth(int lo, int hi, int k) {
        /*
        1 = 1 (0)
        2 = 1 (1)
        3 = 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1 (7)
        4 = 12 -> 6 -> 3 -> 10 -> ... 
        5 = 16 -> 8 -> ... 
        */
        
        unordered_map<int, int> steps;
        steps[1] = 0;
        priority_queue<pair<int, int>> pq;
        for (int i=lo; i<=hi; ++i) {
            pq.push(pair(getSteps(i, steps), i));
            if (pq.size() == k+1) pq.pop();
        }
        
        return pq.top().second;
    }
    
    int getSteps(int n, unordered_map<int, int>& steps) {
        if (steps.count(n)) return steps[n];

        if (n & 1) return steps[n] = getSteps(n*3+1, steps) + 1; // odd 
        return steps[n] = getSteps(n >> 1, steps) + 1;
    };
    
};