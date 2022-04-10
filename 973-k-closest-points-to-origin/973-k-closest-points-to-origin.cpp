class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue <vector<int>, vector<vector<int>>, compare > max_heap;
        vector<vector<int>> ret;

        for (vector<int>& pair:points){
            max_heap.push(pair);
            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }
        
        int cnt = 0;
        
        while(!max_heap.empty()) {
            ret.push_back(max_heap.top());
            max_heap.pop();
        }
        
        return ret;
    }
    
    struct compare {
        bool operator()(vector<int>&p, vector<int>&q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};