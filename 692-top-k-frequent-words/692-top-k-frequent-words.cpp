class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> hashM;
        
        auto compare = [](pair<int, string> a, pair<int, string> b) {
            if (a.first == b.first) 
                return a.second > b.second;
            
            return a.first < b.first;
        };
        
        int maxFreq = -1;
        for (auto & w : words) {
            hashM[w]++;
            maxFreq = max(maxFreq, hashM[w]);
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)> pq(compare);
        
        for (auto& cur : hashM)
            pq.push({cur.second, cur.first});
        
        int cnt = 0;
        vector<string> ans;
        while (!pq.empty() && cnt < k){
            auto cur = pq.top(); pq.pop();
            ans.push_back(cur.second);
            cnt ++;
        }
        
        return ans;
    }
};