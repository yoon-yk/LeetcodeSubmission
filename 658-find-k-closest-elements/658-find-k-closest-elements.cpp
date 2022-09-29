class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    
        // cout << " ******" << endl;
        int n = arr.size();
        vector<int> ans;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int leftBound = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        
        for (int i=0; i<leftBound; i++) 
            maxHeap.push(arr[i]);
        
        for (int i=leftBound; i<n; i++)
            minHeap.push(arr[i]);

        while (ans.size() < k) {

            if (!maxHeap.empty() && !minHeap.empty()) {
                
                int left = maxHeap.top();
                int right = minHeap.top();
                
                if (abs(left-x) <= abs(right-x)) {
                    ans.emplace_back(left);
                    maxHeap.pop();
                } else {
                    ans.emplace_back(right);
                    minHeap.pop();
                }
            } 

            else if (!maxHeap.empty()) {
                ans.emplace_back(maxHeap.top());
                maxHeap.pop();
            }
            else if (!minHeap.empty()) {
                ans.emplace_back(minHeap.top());
                minHeap.pop();
            }
               
        }
        
        sort(ans.begin(), ans.end());
        return ans;

    }
};