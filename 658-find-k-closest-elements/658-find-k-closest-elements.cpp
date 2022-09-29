class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            int n = arr.size();
        vector<int> ans;

        int lowerBound = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int leftPtr = lowerBound-1, rightPtr = lowerBound;
        // cout << arr[leftPtr] << " " << arr[rightPtr] << endl;

        while (ans.size() < k) {
            // cout << arr[leftPtr] << " " << arr[rightPtr] << endl;
            if (leftPtr > -1 && rightPtr < n) {
                
                int left = arr[leftPtr];
                int right = arr[rightPtr];
                
                if (abs(left-x) > abs(right-x)) {
                    ans.emplace_back(right);
                    rightPtr++;
                } else {
                    ans.emplace_back(left);
                    leftPtr--;
                }
            } 

            else if (rightPtr >= n) {
                ans.emplace_back(arr[leftPtr]);
                leftPtr--;
            }
            else if (leftPtr < 0) {
                ans.emplace_back(arr[rightPtr]);
                rightPtr++;
            }
               
        }
        
        sort(ans.begin(), ans.end());
        return ans;

    }
};