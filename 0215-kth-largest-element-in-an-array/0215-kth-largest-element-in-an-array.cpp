class Solution {
public:
    void sort(int start, int mid, int end, vector<int>& nums) {
        vector<int> temp;
        int ptr1=start, ptr2=mid+1;
        
        while (ptr1 <= mid && ptr2 <= end) {
            if (nums[ptr1] < nums[ptr2]) {
                temp.emplace_back(nums[ptr1]);
                ptr1++;
            } else {
                temp.emplace_back(nums[ptr2]);
                ptr2++;
            }
        }
        
        while (ptr1 <= mid) {
            temp.emplace_back(nums[ptr1]);
            ptr1++;
        }
        
        while (ptr2 <= end) {
            temp.emplace_back(nums[ptr2]);
            ptr2++;
        }
        
        for (int i=0; i<temp.size(); i++)
            nums[i+start] = temp[i];
    }
    
    void mergeSort(int start, int end, vector<int>& nums) {
        if (start >= end) return;
        int mid = start + ((end-start) >> 1);
        
        mergeSort(start, mid, nums);
        mergeSort(mid+1, end, nums);
        sort(start, mid, end, nums);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, end = nums.size()-1;
        mergeSort(start, end, nums);
        
        return nums[nums.size()-k];
    }
};