class Solution {
public:
    int kColSize = 6;

    inline pair<int, int> getPos(int pos) {
        return {pos/kColSize, pos%kColSize};
    }
    
    inline int getCost(int src, int des) {
        auto [srcX, srcY] = getPos(src);
        auto [desX, desY] = getPos(des);
        
        return abs(srcX-desX) + abs(srcY-desY);
    }
    
    int minimumDistance(string word) {  
        
        auto compare = [](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]) return a[3] < b[3];
            return a[0] > b[0];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
        vector<vector<vector<bool>>> mp(word.size(), vector<vector<bool>>(27, vector<bool>(27, false)));
        
        int cost, fpos, spos, idx;
        pq.push({0, 26, 26, 0});
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            cost = cur[0], fpos = cur[1], spos = cur[2], idx = cur[3];
            if (idx == word.size()) return cost;
            
            if (mp[idx][fpos][spos]) continue;
            mp[idx][fpos][spos] = true;
            
            // target 
            int target = word[idx]-'A';
            auto [targetX, targetY] = getPos(target);
            
            // fpos
            if (fpos < 26) {
                pq.push({cost+getCost(fpos, target), target, spos, idx+1});
            } else pq.push({cost, target, spos, idx+1});
            
            // spos
            if (spos < 26) {
                pq.push({cost+getCost(spos, target), fpos, target, idx+1});
            } else pq.push({cost, fpos, target, idx+1});
        }
        
        return 0;
    }
};