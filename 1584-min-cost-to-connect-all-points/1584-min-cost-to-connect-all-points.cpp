class Node {
public :
    int start;
    int end;
    int dist;
    Node(int _start, int _end, int _dist) : start(_start), end(_end), dist(_dist) {};
};

class Solution {
public:
    
    vector<int> parent;
    vector<int> size;

    int find (int idx) {
        if (parent[idx] == idx) return idx;
        return parent[idx] = find(parent[idx]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        size.resize(n, 1);
        for (int i=0; i<n; i++) parent[i] = i;
        
        auto sort = [](Node*a, Node*b){return a->dist>b->dist;};
        priority_queue<Node*, vector<Node*>, decltype(sort)> pq(sort);
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                pq.push(new Node(i, j, abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])));
            }
        }
        
        int ans = 0, cnt = n;
        while (!pq.empty() && cnt > 1) {
            auto cur = pq.top(); pq.pop();
            int start = cur->start, end = cur->end, dist = cur->dist;
            int par1 = find(start), par2 = find(end);
            if (par1 == par2) continue;
            ans += dist;
            if (size[par2] > size[par1]) parent[par1] = par2, size[par2] += size[par1];
            else parent[par2] = par1, size[par1] += size[par2];
            cnt--;
        }
        
        return ans;
    }
};