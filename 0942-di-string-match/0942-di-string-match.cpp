class Solution {
public:
    vector<int> diStringMatch(string s) {
     
        vector<int> v(s.size()+1);
        int lo = 0, hi = s.size();
        for (int i=0; i<s.size(); ++i){
            if (s[i] == 'I') {
               v[i] = lo++;
            } else {
               v[i] = hi--;
            }
        }
        v[s.size()] = lo;
        
        return v;
    }
};