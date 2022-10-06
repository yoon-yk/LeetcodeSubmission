class TimeMap {
public:
    unordered_map<string, map<int, string>> hashM;
    // unordered_map<string, vector<pair<int, string>> hashM
    // keep vector always sorted
    // lower_bound
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashM[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {

        if (hashM.find(key) == hashM.end())
            return "";
        
        auto it = hashM[key].upper_bound(timestamp);
        if (it == hashM[key].begin())
            return "";
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */