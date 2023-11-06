class SeatManager {
public:

    /*
    pq 2 3
    
    */
    // priority_queue<int, vector<int>, greater<>> pq;
    // vector<int> filled;
    multiset<int> avail;
    // int cur = 1;
    SeatManager(int n) {
        // pq.push(1);
        // filled.size(n, false);
        avail.insert(1);
    }
    
    int reserve() {
        auto ret = *avail.begin();
        avail.erase(avail.begin());
        if (avail.empty()) avail.insert(ret+1);
        return ret;
        // filled
        // filled[cur] = true;
        
        // auto cur = pq.top(); 
        // pq.push(cur+1);
        // return cur;
    }
    
    void unreserve(int seatNumber) {
        avail.insert(seatNumber);
        // if (pq.top() > seatNumber)
        //     pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */