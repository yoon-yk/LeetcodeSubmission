class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string num = to_string(n);
        int size = num.length();
        
        unordered_map<string, int> hashM;
        string s;
        for (int i=1; i<=pow(10, size); i<<=1) {
            if (pow(10, size-1)>i) continue;
            s = to_string(i);
            sort(s.begin(), s.end());
            hashM[s]++;
        }
        
        sort(num.begin(), num.end());
        
        return hashM.count(num);
        
    }
    
};