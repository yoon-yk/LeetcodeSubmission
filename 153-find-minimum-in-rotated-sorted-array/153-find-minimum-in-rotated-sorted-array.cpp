class Solution {
public:
    int findMin(vector<int>& nums) {
        
        // 4, 5, 6, 7, 8, 9, 1, 2, 3
        // 7, 8, 9, 1, 2, 3, 4, 5, 6
        int left = 0, right = nums.size()-1, mid;
        while (left < right){
            mid = left + (right-left)/2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else right = mid;
        }
        return nums[left]; 
    }
};