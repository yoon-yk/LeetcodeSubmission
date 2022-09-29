class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        // output : the list of the IDs of the processes will be killed 
        // every children of the processes that i would kill
        
        // make a tree 
            // root --> if ppid is 0
            // append children --> ppid 
        
        // recursively find the all process that will be klled 
        
        unordered_map<int, vector<int>> children;
        
        for (int i=0; i<ppid.size(); i++) { // O(n) , n = number of nodes 
            children[ppid[i]].push_back(pid[i]);
        }
        
        /*
        children
        3 --> 1, 5 
        0 --> 3
        5 --> 10
        */
        
        
        queue<int> q;
        vector<int> ans;
        int root = kill;
        q.push(root);
        
        while (!q.empty()) {
            root = q.front(); q.pop();
            ans.push_back(root);
            for (int & child : children[root])
                q.push(child);
        }
        
        return ans;
        
    }
    
};