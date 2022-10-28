class Solution {
public:
      int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> LA, LB;
        int N = A.size();
        unordered_map<int, int> count;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j<N; ++j){
                if (A[i][j])
                    LA.push_back(i*100+j); 
                if (B[i][j])
                    LB.push_back(i*100+j);
            }

        for (int &i : LA) 
            for (int &j : LB) 
                count[i - j]++;
        int res = 0;
        for (auto &it : count) 
            res = max(res, it.second);
        return res;
    }
};