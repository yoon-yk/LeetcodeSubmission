class Solution {
public:
   bool reorderedPowerOf2(int N) {
        vector<int> A = count(N);
        for (int i = 0; i < 31; ++i)
            if (A == count(1 << i)) {
                return true;
            }
       return false;
    }

    
    vector<int> count(int N) {
        vector<int> ans(10, 0);
        while (N > 0) {
            ans[N % 10]++;
            N /= 10;
        }
        return ans;
    }
};