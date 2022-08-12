class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        
        unordered_map<char, int> hashM; 
        
        auto compare = [] (pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        };
        
        
        int maxCnt = INT_MIN;
        for (const char& c:s) {
            hashM[c]++;
            maxCnt = max(hashM[c], maxCnt);
        }
        
        // if (s.size() - maxCnt < maxCnt - 1) return ans;
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compare)> pq(compare);

        for (auto h : hashM) {
            pq.push({h.first, h.second});
        }        
        
        char firstCh, secondCh;
        int firstCnt = 0, secondCnt = 0;
        
        while (pq.size() > 1) {
            auto firstCh = pq.top(); pq.pop();
            auto secondCh = pq.top(); pq.pop();
            
            ans += firstCh.first;
            ans += secondCh.first;
            
            firstCh.second--;
            secondCh.second--;
            
            if (firstCh.second > 0) 
                pq.push({firstCh.first, firstCh.second});
            if (secondCh.second > 0) 
                pq.push({secondCh.first, secondCh.second});
        }
        
        if (!pq.empty()) {
            auto lastCh = pq.top(); pq.pop();
            if (lastCh.second > 1) return "";
            ans += lastCh.first;
        }
        
        
        return ans;
    }
};