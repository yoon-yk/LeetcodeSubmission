class Solution {
public:
    
    bool isPossible(vector<int>& weights, int maxW, int days) {
        int cnt = 1, curSum = 0;
        for (int & w : weights) {
            if (curSum + w > maxW) {
                cnt ++;
                curSum = 0;
            }
            curSum += w;
        }
        
        return (cnt <= days);
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, minW = INT_MAX;
        for (int & w : weights) sum += w;        
        int start = *max_element(weights.begin(), weights.end()), end = sum;
        while (start <= end){
            int mid = start + ((end-start) >> 1);
            if (isPossible(weights, mid, days))
                end = mid-1;
            else start = mid + 1;
        }
        return start;
    }
};