class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;

        int lowerBound = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int leftPtr = lowerBound-1, rightPtr = lowerBound;

        int cnt = 0;
        while (cnt < k) {
            if (leftPtr > -1 && rightPtr < n) {
                
                int left = arr[leftPtr];
                int right = arr[rightPtr];
                
                if (abs(left-x) > abs(right-x)) {
                    rightPtr++;
                } else {
                    leftPtr--;
                }
            } 

            else if (rightPtr >= n) 
                leftPtr--;
            
            else if (leftPtr < 0) 
                rightPtr++;
            
            cnt++;
        }
        
        // cout << leftPtr <<" " << rightPtr << endl;
        for (int i=max(0, leftPtr+1); i<min(rightPtr, n); i++) {
            ans.push_back(arr[i]);
        }
        
        return ans;

    }
};