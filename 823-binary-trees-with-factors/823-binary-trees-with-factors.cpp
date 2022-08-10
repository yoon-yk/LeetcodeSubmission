class Solution {
public:
    int MOD = 1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        long ans = 0;
        sort(arr.begin(), arr.end());
        unordered_map<int, long> hashM;        
        for (int n : arr)
            hashM[n]++;
        
        for (int rootI=0; rootI<arr.size(); rootI++) {
            double sqrtRoot = sqrt(arr[rootI]);
            for (int leftI=0; arr[leftI]<=sqrtRoot; leftI++) {
                if (arr[rootI] % arr[leftI]) continue;
                int right = arr[rootI] / arr[leftI]; // right는 root보다 작은 값
                if (hashM.count(right)) { // 완전히 나누어 떨어지는 값이어야 함. 
                    hashM[arr[rootI]] += (hashM[arr[leftI]] * hashM[right]) * ((arr[leftI] == right)? 1 : 2);
                    hashM[arr[rootI]] %= MOD;
                }
            }
            ans += hashM[arr[rootI]];
            ans %= MOD;
        }
        
        return ans;
    }
};