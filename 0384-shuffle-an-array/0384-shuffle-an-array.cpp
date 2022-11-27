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
        int rand = random() % 10;
        int size = n.size(), idx1, idx2;
        while (rand--) {
            idx1 = random() % size;
            idx2 = random() % size;
            swap(n[idx1], n[idx2]);
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