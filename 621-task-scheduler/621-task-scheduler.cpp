class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int lenTasks = tasks.size();        
        if (lenTasks==0) return 0;
        if (n==0) return lenTasks;

        unordered_map<int, int> dict;
        
        int maxN = 0, maxL;
        for (int i=0; i<lenTasks; i++) {
            dict[tasks[i]] += 1;
            maxN = max (dict[tasks[i]], maxN);
        }
        
        maxL = (maxN-1)*(n+1);
        
        for (auto c:dict){
            if(c.second == maxN) maxL++;
        }
        

        return max(maxL, lenTasks);
        
    }
};