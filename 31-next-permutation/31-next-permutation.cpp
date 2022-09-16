class Solution {
public:
    
    /*
     [1, 2, 3]
    1 1 2 2 3 3
    2 3 1 3 1 2
    3 2 3 1 2 1
    
    
    naive - permutation(swap) 해서 몇번째에 해당하는지 확인하기
    
    */
    void nextPermutation(vector<int>& nums) {
        
        int i=nums.size()-1;
        for (; i>0; i--){
            if (nums[i-1] < nums[i]) break;
        }

        if (i==0) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int minimum = nums[i-1];
        sort(nums.begin() + i, nums.end());
        
        int nextDigitIdx = upper_bound(nums.begin()+i, nums.end(), minimum) - nums.begin();
        swap(nums[i-1], nums[nextDigitIdx]);
        
    }
};