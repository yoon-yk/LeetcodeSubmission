class Solution {
public:
    map<string, vector<int>> userQ;

    void insertTime(string& userName, string& time) {
        int curTime = stringTimeToNumber(time);
        userQ[userName].push_back(curTime);
    }
    
    int stringTimeToNumber(string& time) {
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));
        
        int totalMin = hour * 60 + min;
        return totalMin;
    }
    
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        
        int n = keyName.size();
        set<string> setAns;
        
        for (int i=0; i<n; i++)
            insertTime(keyName[i], keyTime[i]);
        
        vector<string> ans;
        for (auto & user : userQ) {
            string name = user.first;
            auto logs = user.second;
            sort (logs.begin(), logs.end());
            if (logs.size() < 3) continue;
            
            for (int i=2; i<logs.size(); i++) {
                if (logs[i-2] + 60 >= logs[i]) {
                    ans.push_back(name);
                    break;
                }
            }

        }
        
        return ans;
    }
};