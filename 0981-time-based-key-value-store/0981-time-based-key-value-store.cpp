class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // 같거나 작은 것 == 큰 것 이전의 것 
        if (!mp.count(key)) return "";
        pair<int, string> target = {timestamp+1, ""};
        auto it = upper_bound(mp[key].begin(), mp[key].end(), target);
        if (it == mp[key].begin()) return "";
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */