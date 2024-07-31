class Solution {
public:
    bool isValid(string& time) {
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(2, 2));

        return 0 <= hour && hour < 24 && 0 <= min && min < 60;
    }

    void produce(string& digits, string& curTime, string& target, string& ans) {

        if (!ans.empty()) return;

        if (curTime.size() == 4) {
            // cout << curTime << endl;

            if (!isValid(curTime)) return;
            if (stoi(target) < stoi(curTime)) {
                // cout << target << " " << curTime << endl;
                ans = curTime;
                return;
            }
            return;
        }

        for (int i=0; i<digits.size(); ++i) {
            if (i > 0 && digits[i-1] == digits[i]) continue;
            // cout << curTime << "**" << digits[i] << endl;
            curTime.push_back(digits[i]);
            produce(digits, curTime, target, ans);
            curTime.pop_back();
        }
        return;
    }

    inline string getForm(string ans) {
        return ans.substr(0, 2) + ":" + ans.substr(2, 2);
    }

    inline string getSmallest(char &a) {
        return getForm(string(4, a));
    }

    string nextClosestTime(string time) {
        string digits = time.substr(0, 2) + time.substr(3, 2);
        time = digits;
        sort(digits.begin(), digits.end());

        string curTime, ans = "";
        // cout << ans.empty() << endl;
        produce(digits, curTime, time, ans);

        if (ans.empty()) return getSmallest(digits[0]);
        return getForm(ans);
    }
};