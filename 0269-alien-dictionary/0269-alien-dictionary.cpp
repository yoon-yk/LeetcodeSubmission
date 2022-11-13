class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        vector<vector<int>> adjList(26, vector<int>(26, 0));
        vector<int> indeg(26, 0);
        vector<bool> exist(26, 0);
        
        int chCnt = 0;
        for (auto & word : words) {
            for (auto & c : word) {
                if (exist[c-'a']) continue;
                exist[c-'a'] = true; 
                chCnt ++;
            }
        }
                
        int n = words.size(); 
        for (int w=0; w<n-1; w++) {
            string& word1 = words[w];
            string& word2 = words[w+1];
            
            int ptr1 = 0, ptr2 = 0;
            while (ptr1<word1.size() && ptr2 < word2.size() && word1[ptr1] == word2[ptr2]){
                ptr1++, ptr2++;
            } 
            
            if (ptr1 != word1.size() && ptr2 == word2.size()) return "";
            else if (ptr1 == word1.size()) continue;

            int firstCh = word1[ptr1]-'a', secondCh = word2[ptr2]-'a';
        
            if (adjList[firstCh][secondCh]) continue;
            adjList[firstCh][secondCh] = true;
            indeg[secondCh] ++;        
        }
        
        queue<int> Q;
        for (int i=0; i<26; i++) {
            if (exist[i] && indeg[i] == 0) Q.push(i);
        }
        
        string ans;
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                int cur = Q.front(); Q.pop();
                ans += (cur+'a');
                
                for (int i=0; i<26; i++) {
                    if (adjList[cur][i]) {
                        indeg[i]--;
                        if (indeg[i] == 0)
                            Q.push(i);
                    }
                }
            }
        }
        
        return (ans.size() == chCnt) ? ans : "";
        
    }
};