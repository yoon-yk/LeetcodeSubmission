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
        unordered_map<int, Employee*> mp;
        for (auto & emp : employees) {
            mp[emp->id] = emp;
        }
        
        int ans = 0, cur = id;
        ans += dfs(cur, mp);
        return ans;
    }
    
    int dfs(int cur, unordered_map<int, Employee*> mp) {
        int ans = mp[cur]->importance;
        
        for (auto & sub : mp[cur]->subordinates) {
            ans += dfs(sub, mp);
        }
        
        return ans;
    }
};