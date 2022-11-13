class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqCount;
        int n = nums.size();
        for (int i=0; i<n; i++)
            freqCount[nums[i]]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ; // freq : val 
        for (auto &[val, freq] : freqCount) {
            PQ.push({freq,val});
            if (PQ.size() > k) PQ.pop();
        }
            
        vector<int> ans;
        while (!PQ.empty()) {
            auto cur = PQ.top(); PQ.pop();
            ans.push_back(cur.second);
        }
        
        return ans;
    }
};