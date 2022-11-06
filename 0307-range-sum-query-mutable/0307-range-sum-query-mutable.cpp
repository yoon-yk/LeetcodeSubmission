class SegmentTree {
private : 
    vector<int> tree;

public :
    SegmentTree(vector<int>& nums) {
        int n = nums.size();
        tree.resize(n*4);
        for (int i=0; i<n; i++)
            update(1, 0, n-1, i, nums[i]);
        // for (int& n : tree)
        //     cout << n << " ";
        // cout << endl;
    }
    
    void update(int cur, int cur_left, int cur_right, int idx, int val) {
        if ((cur_left == cur_right) && (cur_left == idx)) {
            tree[cur] = val;
        } else {
            int cur_mid = (cur_left + cur_right) >> 1;
            if (idx <= cur_mid)
                update(cur*2, cur_left, cur_mid, idx, val);
            else update(cur*2+1, cur_mid+1, cur_right, idx, val);
            tree[cur] = tree[cur*2] + tree[cur*2 + 1];
        }
        
    }
    
    int query(int cur, int cur_left, int cur_right, int query_left, int query_right) {
        if (cur_left > query_right || cur_right < query_left) 
            return 0;
        if (query_left <= cur_left && cur_right <= query_right)
            return tree[cur];
        int cur_mid = (cur_left+cur_right) >> 1;
        return query(cur*2, cur_left, cur_mid, query_left, query_right) + 
            query(cur*2+1, cur_mid+1, cur_right, query_left, query_right);
    }

    
};
class NumArray {
private: 
    SegmentTree *tree;
    int n;

public:
    
    NumArray(vector<int>& nums) {
        tree = new SegmentTree(nums);
        n = nums.size();
    }
    
    void update(int index, int val) {
        tree->update(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return tree->query(1, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */