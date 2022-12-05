class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        // graph ?
        // find adjacent list
        int n = bombs.size(); 
        int fX, fY, fR, sX, sY, sR;
        vector<vector<int>> adjList(n);
        
        for (int i=0; i<bombs.size(); i++) {
            fX = bombs[i][0], fY = bombs[i][1], fR = bombs[i][2];
            for (int j=i+1; j<bombs.size(); j++) {
                sX = bombs[j][0], sY = bombs[j][1], sR = bombs[j][2];
                double dist = sqrt(pow(fX-sX, 2)+pow(fY-sY, 2));
                if (dist <= (double)(fR)) 
                    adjList[i].push_back(j);
                if (dist <= (double)(sR)) 
                    adjList[j].push_back(i);
            }
        }
        
        int ans = 0;
        // do dfs for every bombs
        
        int curCnt;
        for (int i=0; i<n; i++) {
            vector<int> visited(n, false);
            visited[i] = true;
            curCnt = dfs(i, visited, adjList);
            ans = max(ans, curCnt);
        }
        
        // and get the maximum result
        return ans;
    }
    
    int dfs(int idx, vector<int> &visited, vector<vector<int>>& adjList) {

        int ans = 0;
        for (int& nei : adjList[idx]) {
            if (visited[nei]) continue;
            visited[nei] = true;
            ans += dfs(nei, visited, adjList);
        }

        return ans + 1;
    }
};