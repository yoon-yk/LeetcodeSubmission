class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> freq(10000, 0);
        for (int & c : deck) ++freq[c];
        
        int g = -1;
        for (int i=0; i<10000; ++i) {
            if (freq[i] > 0) {
                if (g == -1) g = freq[i];
                else g = gcd(g, freq[i]);
            }
        }
        return g >= 2;
    }
    
    int gcd(int x, int y) {
        return x==0 ? y : gcd(y%x, x);
    }
};