class Solution {
public:
    bool isValidTime(const std::string& time) const {
        int hour = std::stoi(time.substr(0, 2));
        int minute = std::stoi(time.substr(2, 2));
        return hour >= 0 && hour < 24 && minute >= 0 && minute < 60;
    }

    std::string getNextTime(const std::string& digits, const std::string& currentTime) {
        std::string nextTime = currentTime;
        while (true) {
            incrementTime(nextTime);
            if (isValidTime(nextTime) && isTimeComposedOfDigits(nextTime, digits)) {
                return nextTime;
            }
        }
    }

    void incrementTime(std::string& time) {
        int hour = std::stoi(time.substr(0, 2));
        int minute = std::stoi(time.substr(2, 2));
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
        time = (hour < 10 ? "0" : "") + std::to_string(hour) + (minute < 10 ? "0" : "") + std::to_string(minute);
    }

    bool isTimeComposedOfDigits(const std::string& time, const std::string& digits) const {
        for (char ch : time) {
            if (digits.find(ch) == std::string::npos) {
                return false;
            }
        }
        return true;
    }

    std::string nextClosestTime(std::string time) {
        std::string digits = time.substr(0, 2) + time.substr(3, 2);
        std::sort(digits.begin(), digits.end());
        std::string currentTime = time.substr(0, 2) + time.substr(3, 2);
        std::string nextTime = getNextTime(digits, currentTime);
        return nextTime.substr(0, 2) + ":" + nextTime.substr(2, 2);
    }
};