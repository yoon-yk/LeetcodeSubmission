class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        divide(nums, 0, nums.size()-1);
        return nums;
    }
    void divide(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;
        
        int mid = (start + end) >> 1;
        divide(nums, start, mid);
        divide(nums, mid+1, end);
        conquer(nums, start, mid, end);
    }
    
    void conquer(vector<int>& nums, int start, int mid, int end) {
        int ptr1 = start, ptr2 = mid+1;
        vector<int> temp;
        while (ptr1 <= mid && ptr2 <= end) {
            if (nums[ptr1] < nums[ptr2]) {
                temp.push_back(nums[ptr1]);
                ptr1++;
            } else {
                temp.push_back(nums[ptr2]);
                ptr2++;
            }
        }
        
        while (ptr1 <= mid) {
            temp.push_back(nums[ptr1]);
            ptr1++;
        }
        
        while (ptr2 <= end) {
            temp.push_back(nums[ptr2]);
            ptr2++;
        }
        
        for (int i=start; i<=end; i++) {
            nums[i] = temp[i-start];
        }
    }
};