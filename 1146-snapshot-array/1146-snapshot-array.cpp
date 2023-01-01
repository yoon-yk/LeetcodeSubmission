class SnapshotArray {
public:
    
    /*
    0 1 2 3
  ---------
  1     4 
  2   4
    */
    
    int snapID;
    vector<vector<pair<int, int>>> arr;
    SnapshotArray(int length) {
        snapID = 0;
        arr.resize(length);
    }
    
    void set(int index, int val) {
        if (!arr[index].empty() && 
            arr[index].back().first == snapID)
            arr[index].back().second = val;
        else arr[index].push_back({snapID, val});
    }
    
    int snap() {
        return snapID++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(), 
                        arr[index].end(), pair(snap_id, INT_MAX));
        if (it == arr[index].begin()) return 0;
        return arr[index][prev(it)-arr[index].begin()].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */