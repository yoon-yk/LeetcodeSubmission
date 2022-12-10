class Solution {
public:

    /* ONE COMPONENT WITH NO CYCLE */
    
    bool ERROR = false;
    
    int initIndegAndCountUniqueChars(vector<string>& words, vector<int>& indeg) {
        int cnt = 0;
        for (auto & word : words) {
            for (auto & c : word){
                if (indeg[c-'a'] != INT_MIN) continue;
                cnt++;
                indeg[c-'a'] = 0;
            }   
        }
        return cnt;
    }
    
    void makeOrder(int c1, int c2, vector<int>& indeg, vector<vector<int>> &adjList) {
        adjList[c1].push_back(c2);
        indeg[c2]++;
    }
    
    void findOrder(vector<string>& words, vector<int>& indeg, vector<vector<int>> &adjList) {
        int n = words.size();
        for (int i=0; i<n-1; i++) {
            string& w1 = words[i]; string& w2 = words[i+1];
            int idx1 = 0, idx2 = 0;
            while (idx1 < w1.size() && idx2 < w2.size() && w1[idx1] == w2[idx2]) 
                idx1++, idx2++;
        
            if (idx1 == w1.size()) continue;
            else if (idx2 == w2.size()) {ERROR = true; return;}
            
            makeOrder(w1[idx1]-'a', w2[idx2]-'a', indeg, adjList);
        }
    }
    
    string alienOrder(vector<string>& words) {
        // order
        // only one pair each 
        // skip until it has the same char
        
        
        vector<vector<int>> adjList(26);
        vector<int> indeg(26, INT_MIN);
        int cnt = initIndegAndCountUniqueChars(words, indeg);
        findOrder(words, indeg, adjList); // fill adjList;
        if (ERROR) return "";        // starting from the letters with no indegree
        
        queue<int> Q;
        for (int i=0; i<26; ++i)
            if (indeg[i] == 0) { Q.push(i); }
        // insert into Q
        
        // topological sort
        string s;
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            s += (char)(cur+'a');
            
            for (auto & nei : adjList[cur]) {
                if (--indeg[nei] == 0)
                    Q.push(nei);
            }
        }
        
        return (s.size() == cnt) ? s : "";
        // if all chars were shown,
        // return the output
        // else return "";
        
    }
};