class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // -1, 2, 1, -4
        // -1 + 2 + 1 = 2
        
        // -4 -1 1 2 
        // a+b+c = target
        // a+b ~ target-c
        
        sort(nums.begin(), nums.end());
        
        int minAbs = INT_MAX;
        int sum = -1;

        int n = nums.size();
        for (int ci=0; ci<n; ++ci) {
            int newT = target - nums[ci];
            int ai = ci+1, bi = n-1;
            while (ai < bi) {
                if (nums[ai] + nums[bi] == newT) {
                    return target;
                } 
                
                if (abs (newT - (nums[ai] + nums[bi])) < minAbs) {
                    minAbs = abs (newT - (nums[ai] + nums[bi]));
                    sum = nums[ai] + nums[bi] + nums[ci];
                }   
                
                if (nums[ai] + nums[bi] < newT) {
                    ++ai;
                } else {
                    --bi;
                }

            }
        }
        return sum;
    }
};