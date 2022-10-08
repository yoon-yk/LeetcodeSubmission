class Solution {
public:
    
    inline void beginSkipDup(vector<int>& nums, int& i) {
        while (i+1<nums.size() && nums[i] == nums[i+1]) i++;
    }
    
    inline void endSkipDup(vector<int>& nums, int& i) {
        while (i-1>0 && nums[i] == nums[i-1]) i--;
    }   
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        
        a + b + c = 0
        
        모두 0 이거나
        적어도 하나는 음수여야 함. ==> 적어도 하나는 양수여야 함 . 
        
        [-4,-1,-1,0,1,2]
        
        
        
        [-4, -1, 0, 1, 2]
          1   2  1  1  1
                
        
          
         -4 + 2 (+ 2) = 0

        
        a + b + c = 0
        a 를 음수라고 하자. 
          |  

        
        a + b = -c (target)
        
        a + b + c = 0
        a + b = -c
        -4 -1 = -5
        
        [-1,0,1,2,-1,-4]
        
          |       |
          
         -4 -2 == -6
         -4 + 2 == -2
        
        */
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        int begin, end;
        
        for (int i=0; i<n && nums[i]<=0; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            begin = i+1, end = n-1;
            while (begin < end) {
                if (nums[begin] + nums[end] + nums[i] == 0) {
                    ans.push_back({nums[i], nums[begin], nums[end]});
                    beginSkipDup(nums, begin);
                    endSkipDup(nums, end);
                    begin++, end--;
                } else if (nums[begin] + nums[end] + nums[i] < 0) {
                    begin++;
                } else {
                    end --;
                }
            }
        }        
        
        return ans;
    }
};