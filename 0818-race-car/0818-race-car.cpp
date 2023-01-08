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
        /*
        A
        pos += speed;
        speed *= 2;
        
        R
        speed = speed > 0 ? speed-1 : 1;
        
        
        0 --> 3
        pos += 1; // pos = 1, speed = 2;
        pos += 2; // pos = 3, speed = 4;
        
        
        0 --> 6
        pos += 1; // pos = 1, speed = 2;
        pos += 2; // pos = 3, speed = 4;
        pos += 4; // pos = 7, speed = 8;
        --speed; // speed = 7;
        --speed; // speed = 6;
        */
        queue<info> Q;
        Q.push(info(0, 1, 0));
        unordered_map<int, unordered_set<int>> visited;
        visited[0].insert(1);
        
        long ap, as, rp, rs;
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            if (cur.pos == target) return cur.len;
            // cout << cur.pos << "/" << cur.speed << "/" << cur.len << endl;
            
            ap = cur.pos+cur.speed, as = cur.speed*2;
            if (!visited[ap].count(as) && 0 < ap && ap < (target << 1)) {
                Q.push(info(ap, as, cur.len+1));
                visited[ap].insert(as);
            }
            
            rp = cur.pos, rs = cur.speed > 0 ? -1 : 1;
            if (!visited[rp].count(rs) && 0 < rp && rp < (target << 1)) {
                Q.push(info(rp, rs, cur.len+1));
                visited[rp].insert(rs);
            }
                
        }
        
        
        return -1;
        
    }
};