class HitCounter {
public:
    queue<int> counter;
    
    HitCounter() {}
    
    void hit(int timestamp) {
        while (!counter.empty() && timestamp-counter.front() >= 300) 
            counter.pop();
        counter.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!counter.empty() && timestamp-counter.front() >= 300) 
            counter.pop();
        return counter.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */