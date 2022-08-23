class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        int len = 8;
        vector<char> cand = {'A', 'C', 'G', 'T'};
        
        unordered_set<string> bankSet(bank.begin(), bank.end());
        
        queue<string> Q;
        Q.push(start);
        unordered_set<string> visited;
        visited.insert(start);
        
        string cur, next;
        int nMutation = 0;
        
        while(!Q.empty()) {
            
            int size = Q.size();
            while (size-- > 0) {
                cur = Q.front(); Q.pop();
                
                if (cur==end) {
                    return nMutation;
                }
                
                next = cur;
                for (int i=0; i<len; i++) {
                  for (int j=0; j<4; j++) {
                      next[i] = cand[j];
                      if (bankSet.find(next)!=bankSet.end() && visited.find(next)==visited.end()) {
                          Q.push(next);
                          visited.insert(next);
                      }
                  }
                    next[i] = cur[i];
                }
                
            }
            nMutation++;
        }
        
        return -1;
    }
};