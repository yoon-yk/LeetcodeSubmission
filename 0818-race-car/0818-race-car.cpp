class info {
public:
    long pos;
    long speed;
    long len;
    info(long _pos, long _speed, long _len) : pos(_pos), speed(_speed), len(_len) {};
};

class Solution {
public:
    int racecar(int target) {
        queue<info> Q;
        Q.push(info(0, 1, 0));
        unordered_map<int, unordered_set<int>> visited;
        
        long ap, as, rp, rs;
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            if (cur.pos == target) return cur.len;
            if (visited[cur.pos].count(cur.speed)) continue;
            visited[cur.pos].insert(cur.speed);
            
            ap = cur.pos+cur.speed, as = cur.speed*2;
            if (0 < ap && ap < target*2) Q.push(info(ap, as, cur.len+1));
            
            if ((cur.pos+cur.speed > target && cur.speed > 0) ||
                 (cur.pos+cur.speed < target && cur.speed < 0)) {
                rp = cur.pos, rs = cur.speed > 0 ? -1 : 1;
                Q.push(info(rp, rs, cur.len+1));   
            }
                
        }
        
        
        return -1;
        
    }
};