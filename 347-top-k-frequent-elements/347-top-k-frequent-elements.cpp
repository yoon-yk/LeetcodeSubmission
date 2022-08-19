class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> hashM;
        for (int n: nums)
            hashM[n]++;
        
        auto compare = [](pair<int, int> a, pair<int, int> b) {
          return a.second < b.second;  
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        
        for (auto n : hashM)
            pq.push({n.first, n.second});
        
        vector<int> ans;
        for (int i=0; i<k; i++) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
            
        return ans;
    }
};