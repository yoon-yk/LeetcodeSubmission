class HitCounter {
public:
    int size;
    deque<pair<int, int>> counter;
    
    HitCounter() {size = 0;}
    
    void hit(int timestamp) {
        while (!counter.empty() && timestamp-counter.front().first >= 300) {
            size -= counter.front().second;
            counter.pop_front();
        }
        
        if (!counter.empty() && counter.back().first == timestamp) 
            ++counter.back().second;
        else counter.push_back({timestamp, 1});
        ++size;
    }
    
    int getHits(int timestamp) {
        while (!counter.empty() && timestamp-counter.front().first >= 300) {
            size -= counter.front().second;
            counter.pop_front();
        }
        return size;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */