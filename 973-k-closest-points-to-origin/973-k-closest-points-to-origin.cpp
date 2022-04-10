class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int dis;
        unordered_map<int, vector<vector<int>>> rank;
        priority_queue <int, vector<int>, greater<int> > min_heap;
        vector<vector<int>> ret;

        for (vector<int>& pair:points) {
            dis = pow(pair[0], 2) + pow(pair[1], 2);
            min_heap.push(dis);
            rank[dis].push_back(pair);
        }
        
        int cnt = 0;
        
        while(cnt < k && !min_heap.empty()) {
            int curDis = min_heap.top();
            min_heap.pop();
            for (auto elm : rank[curDis]) {
                if (cnt >= k) break;
                ret.push_back(elm);
                cnt++;
            }
        }
        
        return ret;
    }
};