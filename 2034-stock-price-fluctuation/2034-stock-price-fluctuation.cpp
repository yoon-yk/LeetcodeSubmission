class StockPrice {
public:
    StockPrice() {}

    // price - timestamp
    int latestTime = -1;
    multiset<int> pq;
    unordered_map<int, int> mp; // timestamp - price
    
    void update(int timestamp, int price) {
        // correcting the price 
        // if same time stamp - correction
        if (mp.count(timestamp)) 
            pq.erase(pq.find(mp[timestamp]));
        // else - update
        mp[timestamp] = price;
        if (timestamp > latestTime)
            latestTime = timestamp;
        pq.insert(price);
    }
    
    int current() {
        // latest 
        if (mp.empty()) return -1;
        return mp[latestTime];
        // needs to be sorted?
    }
    
    int maximum() {
        // maximum 
        return *pq.rbegin();
        // what if it has been corrected afterward?
    }
    
    int minimum() {
        // minimum 
        return *pq.begin();
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