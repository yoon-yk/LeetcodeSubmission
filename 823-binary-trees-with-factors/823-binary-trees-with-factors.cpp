class Solution {
public:
    int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        long ans = 0;
        
        for (int i=0; i<arr.size(); ++i) {
            dp[arr[i]] = 1;
            for (int j=0; j<i; ++j) {
                // arr[i] : target
                // arr[j] : left 
                // arr[i]/arr[j] : right
                
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i]/arr[j];
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[right]) % MOD;

                }
            }
            ans = (ans + dp[arr[i]]) % MOD;
        }
        
        return ans;
    }
};



/*
[2,4,5,10,15,50, 100]

[ 2 ] 
[ 4 ] [ 2, 2]
[ 5 ] 
[ 10] [ 2, 5] [ 5, 2] [10, 10]
[ 50] [10, 5] [5, 10]
[100] [2, 50] [50, 2] 

[2] [4] [5] [10] [15] [50] [100]
 1   2   1    3   1    7     7
 
[2,2,4] [2,5,10] [2,50,100]
1*1 = 1. 1*1 = 1. 1*7 = 7
[5,2,10] [5, 10, 50] [10,5,50] [50,2,100]
1*1 = 1.  1*3 = 3.    3*1 = 3.  7*1 = 7



    50
 10     5
5 2    

    50
 5     10
      5  2    




*/