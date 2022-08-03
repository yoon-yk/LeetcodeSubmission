class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, s_len = s.length(), t_len = t.length();
        if (s_len < t_len) return "";
        if (s == t) return t;
        
        unordered_map<char, int> hashM;
        queue<int> q;
        
        for (int i=0; i<t_len; i++) 
            hashM[t[i]]++;
        int tCnt = hashM.size();
        int minLeft=-1, minRight=-1, minSubLen = INT_MAX;
        
        while (right < s_len) {
            
            if (left == right && !hashM.count(s[left])) {
                while (right < s_len && !hashM.count(s[left])) 
                    right = ++left;
                continue;
            }
            
            if (hashM.find(s[right])!=hashM.end()) {
                q.push(right);
                --hashM[s[right]];
                
                if (hashM[s[right]] == 0)
                    --tCnt;
            }
            
                
           if (tCnt == 0) {
               
                while (!q.empty() && q.front() <= left) q.pop();

            
               cout << "before::"<< left << "::" << right << endl;
               
               while (!q.empty() && hashM[s[left]] < 0) {
                   if (hashM[s[left]] == 0)
                        ++tCnt;
                    ++hashM[s[left]];
                   left = q.front(); q.pop();
               }
               cout << "after::"<< left << "::" << right << endl;

                   
               if (right-left+1 < minSubLen){
                    minLeft = left;
                    minRight = right;
                    minSubLen = right-left+1;

               }
               cout << "min::" << minLeft << "::" << minRight << endl;



               if (!q.empty()) {
                   int next = q.front(); q.pop();

                   while (left < next) {
                        if (hashM.find(s[left])!=hashM.end()) {
                            if (hashM[s[left]] == 0)
                                ++tCnt;
                            ++hashM[s[left]];
                        }
                       ++left;
                    }
                }
           }
            
            
            ++ right;
        }
        
        return (minLeft == -1) ? "" : s.substr(minLeft, minRight-minLeft+1);
    }
};