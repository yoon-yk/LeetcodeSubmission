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
        
        for (int i=0; i<ppid.size(); i++) {
            children[ppid[i]].push_back(pid[i]);
        }
        
        /*
        children
        3 --> 1, 5 
        0 --> 3
        5 --> 10
        */
        
        int root = children[0][0];
        
        queue<int> q;
        
        while (root!=kill) {
            for (int & child : children[root])
                q.push(child);
            root = q.front(); q.pop();
        }

        vector<int> ans;
        while (!q.empty()) q.pop();
        
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