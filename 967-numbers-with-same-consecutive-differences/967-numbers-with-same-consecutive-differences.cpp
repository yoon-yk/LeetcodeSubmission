class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {

        vector<int> ans;
        queue<string> Q;
        unordered_map<string, int> vis;
        
        for (int i=1; i<=9; i++) {
            Q.push(to_string(i));
        }
        
        string curS;
        while (!Q.empty()) {
            
            curS = Q.front(); Q.pop();
            
            if (curS.length() == n) {
                ans.push_back(stoi(curS));
                continue;
            }
        
            int prev = curS.back() - '0';
            if (prev + k < 10) {
                curS += (prev + k) + '0';
                if (vis[curS] == 0) {
                    Q.push(curS);
                    vis[curS]++;
                }
                curS.pop_back();
            }

            if (prev - k >= 0) {
                curS += (prev - k) + '0';
                if (vis[curS] == 0) {
                    Q.push(curS);
                    vis[curS]++;
                }
                curS.pop_back();        
            }
            
        }
        
        return ans;
    }
    
};