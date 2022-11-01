class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, pair<string, double>> gidWeight;
        
        int idx = 0;
        string dividend, divisor, dividendGid, divisorGid;
        double quotient, dividendWeight, divisorWeight;
        for (auto &equation : equations) {
            dividend = equation[0], divisor = equation[1];
            quotient = values[idx];
            unionn (gidWeight, dividend, divisor, quotient);
            idx++;
        }
        
        idx=0;
        vector<double>results(queries.size());
        for (auto& query : queries) {
            dividend = query[0], divisor = query[1];
            
            if (!gidWeight.count(dividend) || !gidWeight.count(divisor)) {
                results[idx] = -1.0;
            } else {
                auto dividendEntry = find(gidWeight, dividend);
                auto divisorEntry = find(gidWeight, divisor);
                
                dividendGid = dividendEntry.first,
                divisorGid = divisorEntry.first;
                dividendWeight = dividendEntry.second,
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
        
        auto entry = gidWeight[nodeId];
        
        if (entry.first != nodeId) {
            auto newEntry = find(gidWeight, entry.first);
            gidWeight[nodeId] = {newEntry.first, entry.second * newEntry.second};
        }
        
        return gidWeight[nodeId];
    }
    
    void unionn(unordered_map<string, pair<string, double>>& gidWeight, string dividend, string divisor, double value) {
        auto dividendEntry = find(gidWeight, dividend);
        auto divisorEntry = find(gidWeight, divisor);
        
        string dividendGid, divisorGid;
        double dividendWeight, divisorWeight;
        
        dividendGid = dividendEntry.first, divisorGid = divisorEntry.first;
        dividendWeight = dividendEntry.second, divisorWeight = divisorEntry.second;
        
        if (dividendGid!=divisorGid) 
            gidWeight[dividendGid] = {divisorGid, divisorWeight*value/dividendWeight};
    }
};