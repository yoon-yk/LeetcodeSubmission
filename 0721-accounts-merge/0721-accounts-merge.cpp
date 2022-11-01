class Solution {
public:
    vector<int> size, parent;
    
    int findd(int e) {
        if (parent[e] == e) return e;
        return parent[e] = findd(parent[e]);
    }
    
    void unionn(int e1, int e2) {
        cout << "e/" << e1 << " " << e2 << endl;
        int p1 = findd(e1), p2 = findd(e2);
        cout << "p/" << p1 << " " << p2 << endl;

        if (p1 == p2) return;
        if (size[p1] > size[p2]) {
            size[p1] += size[p2];
            parent[p2] = p1;
        } else {
            size[p2] += size[p1];
            parent[p1] = p2;   
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        size.resize(n, 1);
        parent.resize(n);
        
        for (int i=0; i<n; i++) parent[i] = i;
        
        int cnt = 0;
        unordered_map<string, int> mp;
        for (auto & acc : accounts) {
            for (int j=1; j<acc.size(); j++) {
                if (mp.count(acc[j])) 
                    unionn(cnt, mp[acc[j]]);
                else mp[acc[j]] = cnt;
            }
            cnt++;
        }

        
        map<int, set<string>> sorted;
        for (int i=0; i<accounts.size(); i++)
            for (int j=1; j<accounts[i].size(); j++)
                sorted[findd(parent[i])].insert(accounts[i][j]);
        
        vector<vector<string>> ans;
        for (auto& [idx, sett] : sorted){
            ans.push_back({accounts[idx][0]});
            for (auto & mails : sett)
                ans.back().push_back(mails);  
        }

        return ans;
    }
};