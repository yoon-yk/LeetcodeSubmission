class Solution {
public:
    /*
    3 3
    3 2 
    3 2 1
    3 2 1 0
    2 2 1 0
    1 1 1 0
    3(4) 2(1) 1(1)
    3(1) 2(1) 1(1)
    */
    
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (int i=0; i<s.size(); ++i)
            ++freq[s[i]-'a'];
        
        priority_queue<int> pq;
        for (int i=0; i<26; ++i) {
            if (freq[i] > 0) pq.push(freq[i]);
        }
        
        int del = 0;
        while (pq.size() > 1) {
            auto cur = pq.top(); pq.pop();
            if (cur == pq.top()) {
                if (cur-1 > 0)
                    pq.push(cur-1);
                ++del;
            }
        }
        
        return del;
    }
};