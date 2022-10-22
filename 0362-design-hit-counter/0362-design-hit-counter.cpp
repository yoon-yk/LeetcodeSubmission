class HitCounter {
public:
    queue<int> Q;
    
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        while (!Q.empty() && Q.front()+300 <= timestamp)
            Q.pop();
        Q.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!Q.empty() && Q.front()+300 <= timestamp)
            Q.pop();
        
        return Q.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */