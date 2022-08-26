class Solution {
public:
    bool reorderedPowerOf2(int N) {
        unordered_set<string> powerOfTwos;
        for (int i = 0; i < 32; ++i) {
            int n = 1 << i;
            string s = to_string(n);
            sort(s.begin(), s.end());
            powerOfTwos.insert(s);
        }
        string s = to_string(N);
        sort(s.begin(), s.end());
        return powerOfTwos.count(s) > 0;
        
    }
};