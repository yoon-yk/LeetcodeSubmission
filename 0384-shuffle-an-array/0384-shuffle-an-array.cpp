class Solution {
public:
    vector<int> n;
    vector<int> orig;
    
    Solution(vector<int>& nums) {
        n = nums;
        orig = nums;
    }
    
    vector<int> reset() {
        n = orig;
        return n;
    }
    
    vector<int> shuffle() {
        for (int i=0; i<n.size(); i++) {
            swap(n[i], n[rand()%(n.size())]);
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