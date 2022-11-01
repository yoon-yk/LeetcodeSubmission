class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, pair<string, double>> gidWeight;
        
        int idx = 0;
        for (auto &equation : equations) {
            string dividend = equation[0];
            string divisor = equation[1];
            double quotient = values[idx];
            
            unionn (gidWeight, dividend, divisor, quotient);
            idx++;
        }
        
        idx=0;
        vector<double>results(queries.size());
        for (auto& query : queries) {
            string dividend = query[0], divisor = query[1];
            
            if (!gidWeight.count(dividend) || !gidWeight.count(divisor)) {
                results[idx] = -1.0;
            } else {
                pair<string, double> dividendEntry = find(gidWeight, dividend);
                pair<string, double> divisorEntry = find(gidWeight, divisor);
                
                string dividendGid = dividendEntry.first,
                       divisorGid = divisorEntry.first;
                double dividendWeight = dividendEntry.second,
                       divisorWeight = divisorEntry.second;
                
                if (dividendGid!=divisorGid) 
                    results[idx] = -1;
                else results[idx] = dividendWeight / divisorWeight;

            }
            
            idx++;
        }
        
        return results;
    }
    
    pair<string, double> find(unordered_map<string, pair<string, double>>& gidWeight, string nodeId) {
        if (!gidWeight.count(nodeId))
            gidWeight[nodeId] = pair<string, double>{nodeId, 1.0};
        pair<string, double> entry = gidWeight[nodeId];
        
        if (entry.first != nodeId) {
            pair<string, double> newEntry = find(gidWeight, entry.first);
            gidWeight[nodeId] = pair<string, double> {newEntry.first, entry.second * newEntry.second};
        }
        
        return gidWeight[nodeId];
    }
    
    void unionn(unordered_map<string, pair<string, double>>& gidWeight, string dividend, string divisor, double value) {
        pair<string, double> dividendEntry = find(gidWeight, dividend);
        pair<string, double> divisorEntry = find(gidWeight, divisor);
        
        string dividendGid = dividendEntry.first,
               divisorGid = divisorEntry.first;
        double dividendWeight = dividendEntry.second,
               divisorWeight = divisorEntry.second;
        
        if (dividendGid!=divisorGid) {
            gidWeight[dividendGid] = pair<string, double>{divisorGid, divisorWeight*value/dividendWeight};
        }
    }
};