class Solution {
public:
    int findTheWinner(int n, int k) {
        int left = n;
        vector<bool> arr(n, true);
        int i = -1, cnt;
        while (left > 1) {
            cnt = 0;
            while (cnt < k) {
                ++i;
                if (arr[i%n]) ++cnt;
            }
            arr[i%n] = false;
            --left;
        }
        
        for (int i=0; i<n; ++i) if (arr[i]) return i+1;
        return -1;
    }
};