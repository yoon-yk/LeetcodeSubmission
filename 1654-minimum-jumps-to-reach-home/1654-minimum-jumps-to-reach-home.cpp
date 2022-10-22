class Solution {
public:
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<pair<int, int>> Q;
        unordered_map<int, unordered_set<int>> visit;
        for (auto& i : forbidden) {
            visit[i].insert(-1);
            visit[i].insert(1);
        }

        Q.push({0, 0}); // pos : -1(backward), 1(forward);
        visit[0].insert(0);
        
        int curTime = 0;
        while (!Q.empty()) {
            
            int size = Q.size();
            while (size--) {
                auto cur = Q.front(); Q.pop();
                int curIdx = cur.first;
                int curDir = cur.second;
                
                if (curIdx == x)
                    return curTime;

                if (curIdx+a <= 6000 && !visit[curIdx+a].count(1)) {
                    Q.push({curIdx+a, 1});
                    visit[curIdx+a].insert(1);
                }
                if (curDir!=-1 && curIdx-b >= 0 && !visit[curIdx-b].count(-1)) {
                    Q.push({curIdx-b, -1});
                    visit[curIdx-b].insert(-1);
                }
                
            }
            curTime ++;
        }
        
        return -1;
    }
};