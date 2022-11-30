class StockPrice {
public:
    unordered_map<int, int> timeStamps;
    multiset<int> prices;
    int latestTS;
    
    StockPrice() {
        latestTS = -1;
    }
    
    void update(int timestamp, int price) {
        
        if (timeStamps.count(timestamp)) {
            prices.erase(prices.find(timeStamps[timestamp]));
        }
        
        latestTS = max(latestTS, timestamp);
        timeStamps[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return timeStamps[latestTS];
    }
    
    int maximum() {
       return *prices.rbegin(); 
    }
    
    int minimum() {
        return *prices.begin();
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