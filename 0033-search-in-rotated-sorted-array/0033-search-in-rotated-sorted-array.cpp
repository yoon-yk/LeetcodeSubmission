class Solution {
public:
    int findStartingIdx(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = (start+end) >> 1;
            if (mid+1 >= nums.size()) break;
            if (nums[mid] > nums[mid+1])
                return mid+1;
            if (nums[mid] < nums[start])
                end = mid-1;
            else start = mid+1;
        }
        return start;
    }
    
    int search(vector<int>& nums, int target) {
        int startingIdx = findStartingIdx(nums, target);
        int findLeft = lower_bound(nums.begin(), nums.begin() + startingIdx-1, target) - nums.begin();
        int findRight = lower_bound(nums.begin() + startingIdx, nums.end(), target) - (nums.begin());
        if (findLeft >= 0 && findLeft < startingIdx && nums[findLeft] == target)
            return findLeft;
        if (findRight >= startingIdx && findRight < nums.size() && nums[findRight] == target)
            return findRight;
        
        return -1;
    }
};