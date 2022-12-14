class Solution {
public:
    
    int partition(vector<int>& nums, int start, int end) {
        
        int randIdx = start + rand() % (end-start+1);
        swap(nums[end], nums[randIdx]);
        
        int part = start;
        for (int i=start; i<end; ++i) {
            if (nums[i] > nums[end]) {
                swap(nums[part], nums[i]);
                part++;
            }
        }
        swap(nums[part], nums[end]);
        return part;
    }
    
    void quicksort(vector<int>& nums, int start, int end, int k) {
        if (start == end) return;
        
        int idx = partition(nums, start, end);
        if (idx == k) return;
        if (idx < k) quicksort(nums, idx+1, end, k);
        else quicksort(nums, start, idx-1, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        quicksort(nums, 0, n-1, k-1);
        
        return nums[k-1];
    }
    
    
};