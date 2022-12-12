class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto & n : nums)
            mp[n]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto & [val, freq] : mp) {
            pq.push({freq, val});
            if (pq.size() == k+1) pq.pop();
        }
        
        vector<int> ans(k);
        for (int i=k-1; i>=0; i--) {
            auto cur = pq.top(); pq.pop();
            ans[i] = cur.second;
        }
        return ans;
    }
};