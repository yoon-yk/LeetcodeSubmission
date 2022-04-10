class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue <vector<int>, vector<vector<int>>, compare > min_heap;
        vector<vector<int>> ret;

        for (vector<int>& pair:points)
            min_heap.push(pair);
        
        int cnt = 0;
        
        while(cnt < k && !min_heap.empty()) {
            ret.push_back(min_heap.top());
            min_heap.pop();
            cnt++;
        }
        
        return ret;
    }
    
    struct compare {
        bool operator()(vector<int>&p, vector<int>&q) {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        }
    };
};