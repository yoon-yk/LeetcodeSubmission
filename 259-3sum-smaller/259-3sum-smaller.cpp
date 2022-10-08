class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        
        /*
        a + b + c < target
        */
        
        int n = nums.size();
        int begin, end;
        int curSum, cnt = 0;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n-2; i++) {
            begin = i+1, end = n-1;
            while (begin < end) {
                curSum = nums[i] + nums[begin] + nums[end];
                if (curSum < target) {
                    cnt += end-begin;
                    begin++;
                } else {
                    end--;
                }
            }
        }
        
        return cnt;
        
    }
    
    
};