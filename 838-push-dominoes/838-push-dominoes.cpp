class Solution {
public:
   string pushDominoes(string s){
        int n = s.length();
        vector<int> l(n, INT_MAX), r(n, INT_MAX);
        
        int count = -1;
        for (int i=0; i<n; i++){
            if(s[i] == 'R'){
                count = 1;
            }
            else if (s[i] == 'L') count = -1;
            else if (count > 0 && s[i] == '.') r[i] = count++;
        }
       
        count = -1;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'L'){
                count = 1;
            }
            else if(s[i] == 'R') count = -1;
            else if (count > 0 && s[i] == '.') l[i] = count++;
        }
       
        string ans = "";
        for(int i=0; i<n; i++){
            if (l[i] == r[i]) ans += s[i];
            else if (l[i] > r[i]) ans += 'R';
            else ans += 'L';
        }
        return ans;
    }
};