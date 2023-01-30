class SnapshotArray {
public:
    int id;
    vector<vector<pair<int, int>>> mp;
    SnapshotArray(int length) {
        mp.resize(length);
        id = 0;
    }
    
    void set(int index, int val) {
        if (!mp[index].empty() && mp[index].back().first == id) {
            mp[index].back().second = val;
        } else mp[index].push_back({id, val});
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        pair<int, int> target = {snap_id+1, -1};
        auto it = upper_bound(mp[index].begin(), mp[index].end(), target);
        if (it == mp[index].begin()) return 0;
        return (*prev(it)).second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */