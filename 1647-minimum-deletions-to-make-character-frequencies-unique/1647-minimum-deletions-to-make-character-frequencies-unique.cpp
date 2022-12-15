class Solution {
public:
    /*
    3 3
    3 2 
    3 2 1
    3 2 1 0
    2 2 1 0
    1 1 1 0
    3(4) 2(1) 1(1)
    3(1) 2(1) 1(1)
    */
    
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (int i=0; i<s.size(); ++i)
            ++freq[s[i]-'a'];
        sort(freq.begin(), freq.end(), greater());
        
        int cnt = 0, j;
        for (int i=0; i<26; ++i) {
            if (freq[i] == 0) break;
            j = i+1;
            while (j<26 && freq[i] == freq[j]) {
                freq[j]--;
                cnt++;
                j++;
            }
        }
        
        return cnt;
    }
};