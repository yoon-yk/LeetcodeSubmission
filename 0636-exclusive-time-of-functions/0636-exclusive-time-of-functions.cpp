class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        /*
        0-0, 1-2, 1-5, 0-6
         2
        
        */
        vector<int> ans(n, 0);
        vector<pair<int, int>> st;
        string id, time, command;
        int curS, curE, preS = -1, preE = -1;
        for (auto & log : logs) {
            stringstream s(log);
            getline(s, id, ':');
            getline(s, command, ':');
            getline(s, time, ':');
            int curId = stoi(id), curTime = stoi(time);
            
            if (command == "start") {
                st.push_back({curId, curTime});
            } else {
                auto latest = st.back(); st.pop_back();
                if (latest.first == curId) {
                    curE = curTime;
                    curS = latest.second;
                    ans[curId] += (curE-curS+1);
                    if (!st.empty()) {
                        ans[st.back().first] -= (curE-curS+1);
                    }
                }
            }
            
        }
        
        return ans;
    }
};