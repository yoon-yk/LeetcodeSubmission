class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> leftMaxH(n, 0), rightMaxH(n, 0);
        
        // Left
        int maxH = 0;
        for (int i=0; i<n; i++) {
            leftMaxH[i] = maxH;
            if (height[i] > maxH) maxH = height[i];
        }
        
        // Right
        maxH = 0;
        for (int i=n-1; i>=0; i--) {
            rightMaxH[i] = maxH;
            if (height[i] > maxH) maxH = height[i];
        }
        
        int sum = 0;
        for (int i=0; i<n; i++) {
            if (leftMaxH[i] > height[i] 
                && rightMaxH[i] > height[i]) {
                sum += min(leftMaxH[i], rightMaxH[i]) - height[i];
            }
        }
        
        return sum;
            
    }
};