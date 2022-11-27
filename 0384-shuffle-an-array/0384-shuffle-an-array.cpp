class Solution {
public:
    vector<int> n;
    vector<int> orig;
    Solution(vector<int>& nums) {
        n = nums;
        orig = nums;
    }
    
    vector<int> reset() {
        return orig;
    }
    
    vector<int> shuffle() {
        int size = n.size(), idx;
        for (int i=0; i<size; i++) {
            idx = random() % size;
            swap(n[i], n[idx]);
        }
        return n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */