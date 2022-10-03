class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        /*
        Input: colors = "abaac", neededTime = [1,2,3,4,5]
        
        
        "a - a a a"
        [4,2,5,4,3]
        
        
        
        */
        
        int n = colors.size(), j;
        int ans = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i=0; i<n-1; i++) {
            
            if (colors[i] == colors[i+1]) {

                j = i;
                pq.push({neededTime[j], j});
                
                j++;
                while (j>0 && j <= n-1 && colors[j-1] == colors[j]) {
                    pq.push({neededTime[j], j});
                    j++;
                }
                
                while (pq.size() > 1) {
                    auto top = pq.top();
                    pq.pop();
                    ans += top[0];
                    // cout << top[0] << endl; 
                }
                
                while (!pq.empty()) pq.pop();
                
                i = j-1;
            }
            
        }
        
        return ans;
    }
};