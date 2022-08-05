class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size(); 
        vector<int> rArr(size+1, 1);
        rArr[size-1] = nums[size-1];
        
        for (int i=size-2; i>=0; i--) {
            rArr[i] =  rArr[i+1]*nums[i];
        }
        
        int currV, prefixProduct = 1;
        for (int i=0; i<nums.size(); i++) {
            currV = nums[i];
            nums[i] = prefixProduct * rArr[i+1];
            prefixProduct *= currV;
        }
        
        return nums;
    }
};