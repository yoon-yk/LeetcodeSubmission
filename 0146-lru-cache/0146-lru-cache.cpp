class LRUCache {
public:
    int max_size;
    list<pair<int, int>> list_pair; // key, value;
    unordered_map<int, list<pair<int, int>>::iterator> keys_map;
    
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        max_size = capacity;
    }
    
    // O(logn) time ( maybe use map? )
    int get(int key) {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator it = keys_map.find(key);
        if(it==keys_map.end()) return -1;
        list_pair.splice( list_pair.begin(), list_pair, it->second );
        return (it->second)->second;
    }
    
    void put(int key, int value) {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator it = keys_map.find(key);
        if(it==keys_map.end()){ // not in the map;
            list_pair.push_front(pair<int, int>{key, value});
            keys_map[key] = list_pair.begin();
        } else {
            it->second->second = value; // keys_map[key]->second = value;
            list_pair.splice( list_pair.begin(), list_pair, it->second ); // list_pair.splice( list_pair.begin(), list_pair, keys_map[key] );
        }
        if(keys_map.size()>max_size){
            pair<int, int> it = list_pair.back();
            keys_map.erase(it.first);
            list_pair.pop_back();
        }
    }
};
