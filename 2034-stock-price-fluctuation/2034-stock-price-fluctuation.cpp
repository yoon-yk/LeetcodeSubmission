class StockPrice {
public:
    StockPrice() {
        
    }
    /*
    1 3
    2 5
    4 2
    
    pq - if not correct, pop
    */
    
    // price - timestamp
    multiset<pair<int, int>> pq;
    map<int, int> mp; // timestamp - price
    
    void update(int timestamp, int price) {
        // correcting the price 
        // if same time stamp - correction
        if (mp.count(timestamp)) {
            if (!pq.empty() && pq.begin()->second == timestamp) 
                pq.erase(pq.begin());
            if (!pq.empty() && (--pq.end())->second == timestamp)
                pq.erase(--pq.end());
        }
        // else - update
        mp[timestamp] = price;
        pq.insert({price, timestamp});
    }
    
    int current() {
        // latest 
        if (mp.empty()) return -1;
        return (--mp.end())->second;
        // needs to be sorted?
    }
    
    int maximum() {
        // maximum 
        
        while (!pq.empty() && mp[(--pq.end())->second] != (--pq.end())->first) {
            pq.erase((--pq.end()));
        }
        return (--pq.end())->first;

        // what if it has been corrected afterward?
    }
    
    int minimum() {
        // minimum 
        while (!pq.empty() && mp[pq.begin()->second] != pq.begin()->first) {
            pq.erase(pq.begin());
        }
        return pq.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */