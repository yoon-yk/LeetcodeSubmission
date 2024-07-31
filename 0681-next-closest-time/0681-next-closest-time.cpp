class Solution {
public:
    bool isValidTime(const string& time) const {
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(2, 2));
        return hour >= 0 && hour < 24 && min >= 0 && min < 60;
    }

    void generateNextTime(const string& digits, string& curTime, const string& targetTime, string& nextTime) {
        if (curTime.size() == 4) {
            if (isValidTime(curTime) && curTime > targetTime && (nextTime.empty() || curTime < nextTime)) {
                nextTime = curTime;
            }
            return;
        }

        for (char digit : digits) {
            curTime.push_back(digit);
            generateNextTime(digits, curTime, targetTime, nextTime);
            curTime.pop_back();
        }
    }

    string formatTime(const string& time) const {
        return time.substr(0, 2) + ":" + time.substr(2, 2);
    }

    string nextClosestTime(string time) {
        string digits = time.substr(0, 2) + time.substr(3, 2);
        string sortedDigits = digits;
        sort(sortedDigits.begin(), sortedDigits.end());

        string targetTime = digits;
        string nextTime;

        string curTime;
        generateNextTime(sortedDigits, curTime, targetTime, nextTime);

        if (nextTime.empty()) {
            return string(1, sortedDigits[0]) + string(1, sortedDigits[0]) + ":" + string(1, sortedDigits[0]) + string(1, sortedDigits[0]);
        }

        return formatTime(nextTime);
    }
};
