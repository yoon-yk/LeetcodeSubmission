class Solution {
public:
    vector<int> diStringMatch(string s) {
        
        /*
        I  D  I  D
        0 -1  0  1
        
        */
        vector<int> v(s.size()+1);
        v[0] = 0;
        for (int i=1; i<=s.size(); ++i){
            if (s[i-1] == 'I') {
               v[i] = v[i-1]+1;
            } else {
               v[i] = v[i-1]-1;
            }
        }
        priority_queue<pair<int, int>> pq;
        for (int i=0; i<v.size(); ++i) pq.push({v[i], i});
        
        int n = v.size()-1;
        while (!pq.empty()){
            auto cur = pq.top(); pq.pop();
            v[cur.second] = n--;
        }
        
        return v;
    }
};