class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> m;
        for (int i = 0; i < equations.size(); i++) {
            m[equations[i][0]].push_back(pair(equations[i][1], values[i]));
            m[equations[i][1]].push_back(pair(equations[i][0], 1.0 / values[i]));
        }
        vector<double> ret;
        for (auto& q : queries){
            if (m.find(q[0]) == m.end() || m.find(q[1]) == m.end())
                ret.push_back(-1.0);
            else if (q[0] == q[1])
                ret.push_back(1.0);
            else {
                unordered_set<string> visited;
                visited.insert(q[0]);
                queue<pair<string, double>> Q;
                Q.push(pair(q[0], 1.0));
                bool found = false;
                while (!Q.empty())
                {
                    string curr = Q.front().first;
                    double ratio = Q.front().second;
                    Q.pop();

                    if (curr == q[1]){
                        ret.push_back(ratio);
                        found = true;
                        break;
                    }
                    for (auto& x : m[curr]){
                        if (visited.count(x.first)) continue;
                        Q.push(pair(x.first, ratio * x.second));
                        visited.insert(x.first);
                    }
                }
                if (!found) ret.push_back(-1.0);
            }
         
        }
        return ret;
    }
};