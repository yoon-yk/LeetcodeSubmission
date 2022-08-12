class Solution {
public:
    string reorganizeString(string s) {
        
        auto compare = [] (pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        };
        
        string ans = "";
        int maxCnt = INT_MIN;
        vector<int> chars(26, 0);
        
        for (const char& c:s) {
            chars[c-'a']++;
            maxCnt = max(chars[c-'a'], maxCnt);
        }
        
        if (s.size() - maxCnt < maxCnt - 1) return ans;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

        for (int i=0; i<26; i++) {
            if (chars[i] > 0)
                pq.push({i, chars[i]});
        }        
        
        while (pq.size() > 1) {
            auto firstCh = pq.top(); pq.pop();
            auto secondCh = pq.top(); pq.pop();
            
            ans += firstCh.first + 'a';
            ans += secondCh.first + 'a';

            if (--firstCh.second > 0) 
                pq.push({firstCh.first, firstCh.second});
            if (--secondCh.second > 0) 
                pq.push({secondCh.first, secondCh.second});
        }
        
        if (!pq.empty()) {
            auto lastCh = pq.top(); pq.pop();
            // if (lastCh.second > 1) return "";
            ans += lastCh.first + 'a';
        }
        
        return ans;
    }
};