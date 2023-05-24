class Solution {
public:
    
    inline long long nH2(int n) { // H(n,2)=C(n+1,2) 
        return (n+1)*n/2;
    }
    
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> min_left(n), min_right(n), max_left(n), max_right(n);
        vector<int> minSt,maxSt;
        
        for (int i=0; i<n; ++i) {
            min_left[i] = min_right[i] = max_left[i] = max_right[i] = i;
        }
        
        
        for (int i=0; i<n; ++i) {
            while (!minSt.empty() && nums[minSt.back()] > nums[i]) {
                min_left[i] = min_left[minSt.back()];
                minSt.pop_back();
            }
            
            while (!maxSt.empty() && nums[maxSt.back()] < nums[i]) {
                max_left[i] = max_left[maxSt.back()];
                maxSt.pop_back();
            }
            
            minSt.push_back(i);
            maxSt.push_back(i);

        }
        
        minSt.clear();  
        maxSt.clear();
        
         for (int i=n-1; i>=0; --i) {
            while (!minSt.empty() && nums[minSt.back()] >= nums[i]) {
                min_right[i] = min_right[minSt.back()];
                minSt.pop_back();
            }
            
            while (!maxSt.empty() && nums[maxSt.back()] <= nums[i]) {
                max_right[i] = max_right[maxSt.back()];
                maxSt.pop_back();
            }
            minSt.push_back(i);
            maxSt.push_back(i);
        }
        
        long long ans = 0;
        for (int i=0; i<n; ++i) {
            long long totalMax = nH2(max_right[i]-max_left[i]+1);
            long long rightDupMax = nH2(max_right[i]-i);
            long long leftDupMax = nH2(i-max_left[i]);
            
            long long totalMin = nH2(min_right[i]-min_left[i]+1);
            long long rightDupMin = nH2(min_right[i]-i);
            long long leftDupMin = nH2(i-min_left[i]);

            
            ans += (totalMax-rightDupMax-leftDupMax) * nums[i];
            ans -= (totalMin-rightDupMin-leftDupMin) * nums[i];

        }

        
        return ans;
    }
};