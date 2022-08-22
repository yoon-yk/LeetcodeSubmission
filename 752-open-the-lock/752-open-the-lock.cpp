class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_map<string, int> deadEnds;
        queue<string> Q;
        
        for (auto & d : deadends) 
            deadEnds[d]++;

        if (deadEnds.count("0000")) return -1;
        Q.push("0000");
        
        int turns = 0;
        while(!Q.empty()) {
            
            int curSize = Q.size();
            while (curSize--) {
                string cur = Q.front(); Q.pop();
                
                if (cur == target) 
                    return turns;

                string inc = cur, dec = cur;
                for (int i=0; i<4; i++) {
                    inc[i] = (cur[i] == '9')? '0' : (cur[i] + 1);
                    dec[i] = (cur[i] == '0')? '9' : (cur[i] - 1);

                    if (!deadEnds.count(inc)) {
                        Q.push(inc);
                        deadEnds[inc]++;
                    }
                    if (!deadEnds.count(dec)) {
                        Q.push(dec);
                        deadEnds[dec]++;
                    }
                    inc[i] = cur[i];
                    dec[i] = cur[i];
                }                   
            }
            turns++;
        }
        
        
        return -1;
    }
};