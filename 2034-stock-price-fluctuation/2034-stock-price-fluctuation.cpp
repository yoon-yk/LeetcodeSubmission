class StockPrice {
public:
    StockPrice() {}

    // price - timestamp
    multiset<int> pq;
    map<int, int> mp; // timestamp - price
    
    void update(int timestamp, int price) {
        // correcting the price 
        // if same time stamp - correction
        if (mp.count(timestamp)) 
            pq.erase(pq.find(mp[timestamp]));
        // else - update
        mp[timestamp] = price;
        pq.insert(price);
    }
    
    int current() {
        // latest 
        if (mp.empty()) return -1;
        return (mp.rbegin())->second;
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