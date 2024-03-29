class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, h, area = 0;
        while (left < right) {
            h = min(height[left], height[right]);
            area = max(area, h*(right-left));
            if (height[left] < height[right]) {
                ++left;
            } else --right;
        }
        return area;
    }
};