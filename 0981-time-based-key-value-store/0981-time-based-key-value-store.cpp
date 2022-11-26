class TimeMap {
public:
    /*
    foo 
    1 bar
    3 bar2 ...
    */
    
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {    
        // vector<string> v= {"a a"," a a", "", "a", "az"};
        // sort(v.begin(), v.end());
        // for (auto & s : v) cout << s << "/" ;
        // cout << endl;
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) return ""; 
        auto & vectorList = mp[key];
        auto ptr = lower_bound(vectorList.begin(), vectorList.end(), pair<int, string>(timestamp+1,""));
        if (ptr == vectorList.begin())
            return "";
        return mp[key][ptr-vectorList.begin()-1].second;
    }
};