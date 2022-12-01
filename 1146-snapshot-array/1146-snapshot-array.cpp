class SnapshotArray {
public:
    
    int curTime = 0;
    
    /*
    curTime = 1
    0 : {-1, 5} {0, 6} {0,8}
    1 : 
    2 :
    3 : 
    */
    vector<map<int, int>> idxM;
    SnapshotArray(int length) {
        idxM.resize(length);
    }
    
    void set(int index, int val) {
        idxM[index][curTime] = val;
    }
    
    int snap() {
        return curTime++;
    }
    
    int get(int index, int snap_id) {
        auto find = idxM[index].upper_bound(snap_id);
        if (find == idxM[index].begin()) return 0;
        return prev(find)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */