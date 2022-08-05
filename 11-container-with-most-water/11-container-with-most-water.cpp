class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int curWater, maxWater = INT_MIN;
        
        while ( left < right ) {
            curWater = (right-left) * min(height[left], height[right]);
            maxWater = max (maxWater, curWater);
            if (height[left] < height[right])
                left ++;
            else right--;
        }
        
        return maxWater;
    }
};