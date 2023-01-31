class HitCounter {
public:
    deque<int> dq;
    
    HitCounter() {}
    
    void hit(int timestamp) {
        dq.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!dq.empty() && timestamp-dq.front() >= 300) 
            dq.pop_front();
        return dq.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */