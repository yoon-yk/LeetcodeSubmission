class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> arr(50001, -1), ans;
        int sum, maxEnd;
        for (auto & p : paint) {
            sum = 0, maxEnd = p[1]-1;
            for (int i=p[0]; i<p[1]; ++i) {
                if (arr[i] == -1) {
                    ++ sum;
                    arr[i] = p[1]-1;
                } else {
                    maxEnd = max(arr[i], maxEnd);
                    i = arr[i];
                } 
            }
            arr[p[0]] = maxEnd;
            ans.push_back(sum);
        }
        

        
        return ans;
    }
};