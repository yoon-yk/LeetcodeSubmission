class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        
        unordered_map<int, unordered_map<int, int>> mp;
        int g, key, d1, d2;
        long long ans = 0;
        for (auto & rec : rectangles) {
            g = gcd(rec[0], rec[1]);
            d1 = rec[0]/g, d2 = rec[1]/g;
            ans += mp[d1][d2];
            ++mp[d1][d2];
        }
        return ans;
    }
    
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
};