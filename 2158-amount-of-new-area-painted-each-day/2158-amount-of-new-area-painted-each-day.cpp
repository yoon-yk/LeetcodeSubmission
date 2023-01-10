class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> arr(50001, -1), ans;
        int sum;
        for (auto & p : paint) {
            sum = 0;
            for (int i=p[0]; i<p[1]; ++i) {
                if (arr[i] == -1) {
                    ++ sum;
                    arr[i] = p[1]-1;
                } else {
                    i = arr[i];
                } 
            }
            ans.push_back(sum);
        }
        return ans;
    }
};