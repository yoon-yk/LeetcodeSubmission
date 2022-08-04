class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int minV = 0, sum = 0;
        // iterate over the array and find the minimum value
        for (const int& n : nums) {
            sum += n;
            minV = min(minV, sum); 
        }
        
        return (minV >= 0) ? 1 : abs(minV) + 1; 
    }
};