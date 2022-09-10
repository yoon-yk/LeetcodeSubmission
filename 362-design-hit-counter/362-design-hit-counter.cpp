/*

1 2 3 4 300 301


*/

class HitCounter {
public:
    
    deque<int> q;
    
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        while (!q.empty() && timestamp- q.front() >= 300)
            q.pop_front();
        q.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!q.empty() && timestamp- q.front() >= 300)
            q.pop_front();
        
        return q.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */