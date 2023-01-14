/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> imp;
        unordered_map<int, vector<int>> subs;
        for (auto & emp : employees) {
            subs[emp->id] = emp->subordinates;
            imp[emp->id] = emp->importance;
        }
        
        int ans = 0, cur = id;
        ans += dfs(cur, imp, subs);
        return ans;
    }
    
    int dfs(int cur, unordered_map<int, int>& imp, unordered_map<int, vector<int>>& subs) {
        int ans = imp[cur];
        
        for (auto & sub : subs[cur]) {
            ans += dfs(sub, imp, subs);
        }
        
        return ans;
    }
};