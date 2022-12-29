class StockPrice {
public:
    
    int cur = -1;
    multiset<pair<int, int>> ms; // price : time
    unordered_map<int, int> mp; // time : price
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        // if exist, update
        if (mp.count(timestamp)) {
            ms.erase({mp[timestamp], timestamp});
        } 
        mp[timestamp] = price;
        ms.insert({price, timestamp});
        cur = max(timestamp, cur);
    }
    
    int current() {
        // latest 
        if (cur == -1) return -1;
        return mp[cur];
    }
    
    int maximum() {
        // maximum price
        if (ms.empty()) return -1;
        return ms.rbegin()->first;
    }
    
    int minimum() {
        // minimum price
        if (ms.empty()) return -1;
        return ms.begin()->first;
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