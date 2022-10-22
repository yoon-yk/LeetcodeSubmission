class Solution {
public:
    
    inline int stringTimeToNumber(string& time) {
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));
        return hour * 60 + min;
    }
    
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        
        vector<string> ans;
        map<string, vector<int>> userQ;

        int n = keyName.size();
        
        for (int i=0; i<n; i++)
            userQ[keyName[i]].push_back(stringTimeToNumber(keyTime[i]));   
        
        for (auto & user : userQ) {
            auto logs = user.second;
            if (logs.size() < 3) continue;
            sort (logs.begin(), logs.end());
            
            for (int i=2; i<logs.size(); i++)
                if (logs[i-2] + 60 >= logs[i]) {
                    ans.push_back(user.first);
                    break;
                }
        }
        
        return ans;
    }
};