class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = (left + right) >> 1;
            int hourSpent = 0;
            
            for (int &pile : piles) 
                hourSpent += (pile / mid + (pile % mid != 0));
            
            if (hourSpent <= h) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};