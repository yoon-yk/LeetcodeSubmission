class Solution {
public:
    bool isValid(const string& time) const {
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(2, 2));
        return hour >= 0 && hour < 24 && min >= 0 && min < 60;
    }

    void produce(const string& digits, string& curTime, const string& target, string& ans) {
        if (!ans.empty()) return;

        if (curTime.size() == 4) {
            if (isValid(curTime) && (stoi(target) < stoi(curTime))) {
                ans = curTime;
            }
            return;
        }

        for (int i=0; i<digits.size(); ++i) {
            if (i > 0 && digits[i-1] == digits[i]) continue;
            curTime.push_back(digits[i]);
            produce(digits, curTime, target, ans);
            curTime.pop_back();
        }
    }

    string getForm(const string& ans) const {
        return ans.substr(0, 2) + ":" + ans.substr(2, 2);
    }

    string getSmallest(char& a) const {
        return getForm(string(4, a));
    }

    string nextClosestTime(string time) {
        string digits = time.substr(0, 2) + time.substr(3, 2);
        time = digits;
        sort(digits.begin(), digits.end());

        string curTime, ans;
        produce(digits, curTime, time, ans);

        if (ans.empty()) return getSmallest(digits[0]);
        return getForm(ans);
    }
};