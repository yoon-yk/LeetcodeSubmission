class Solution {
public:
    vector<string> generatePalindromes(string &s) {
       
        vector<string> ans;
        vector<int> hashM(26, 0);
        for (int i=0; i<s.length(); i++)
            hashM[s[i]-'a']++;
        
        string firstHalf;
        int oddCnt = 0, oddChar = -1, oddCharFreq = 0; 
        for (int i=0; i<26; i++) {
            if (hashM[i] < 1) continue;
            if (hashM[i] % 2) {
                if (++oddCnt > 1)
                    return ans;
                oddChar = i;
            }
            for (int j=0; j < ((hashM[i])>>1); j++) 
                firstHalf += (i + 'a');
        }
 
        permute(0, firstHalf, oddChar, ans);

        return ans;
    }
    
    void permute(int idx, string& s, int oddChar, vector<string>& ans){ 

        int n = s.length();
        
        if (idx == n) {
            string secondHalf = s;
            if (oddChar != -1) 
                secondHalf += oddChar + 'a';
            reverse(secondHalf.begin(), secondHalf.end());
            ans.push_back(s + secondHalf);
            return;
        }

        vector<bool> seen(26, 0);
        for (int i = idx; i<n; i++) {
            if (seen[s[i]-'a']) continue;
            seen[s[i]-'a'] = true;
            swap(s[i], s[idx]);
            permute(idx+1, s, oddChar, ans);
            swap(s[i], s[idx]);
        } 
    }
};