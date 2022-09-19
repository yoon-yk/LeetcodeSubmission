class Solution {
public:
    /*
    a
    a a b
    aa b
    
    
    aa bb aa
    a a b b a a 
    aa b b a a 
    
    - sliding window ? O(n^2)
    길이가 1인경우
    길이가 2인경우
    ...? 
    
    */
    bool isPalindrome(string& s) {
        int front = 0, back = s.length() -1;
        while(front < back) {
            if (s[front] != s[back]) return false;
            front++, back--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        /*
        idx  0 1 2
        pal  a a b
               aa
               
        a a b a a
        a a b aa
        a aba a
        aa b a a
        aa b aa
        aabaa
                
        */
        
        int n = s.length();
        vector<vector<string>> map(n+1);
        
        for (int i=0; i<n; i++) {
            string str;
            for (int j=i; j>=0; j--) {
                str = s[j] + str;
                if (isPalindrome(str)) 
                    map[i+1].push_back(str);
            }
        }
        
        // for (auto c : map) {
        //     for (auto s : c)
        //         cout << s << " ";  
        //     cout << endl;
        // }
        
        vector<string> path;
        vector<vector<string>> ans;
        backtrack(s, n, map, path, ans);
        return ans;
    }
    
    void backtrack(string& s, int idx, vector<vector<string>>& map, vector<string>& path, vector<vector<string>>& ans) {
        
        int n = s.length();
        
        if (idx == 0) {
            
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());

            return;
        }

        
        for (auto& c : map[idx]) {
            path.push_back(c);
            backtrack(s, idx-c.size(), map, path, ans);
            path.pop_back();
        }
    }
    
};