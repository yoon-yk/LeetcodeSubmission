class Solution {
public:
    string decodeString(string s) {
        string ans;
        deque<int> nums;
        deque<string> msgs;
        string num, msg;
        int cnt;
        for (char & c : s) {
            if (isdigit(c)) {
                if (!msg.empty()) {
                    msgs.push_back(msg);
                    msg.clear();
                }
                num += c;
            } else if (c == ']') {
                string cur;
                while (!msgs.empty() && msgs.back() != "[") {
                    cur = msgs.back() + cur;
                    msgs.pop_back();
                }
                msgs.pop_back();
                int cnt = nums.back(); nums.pop_back();
                msgs.push_back(cur);
                for (int i=0; i<cnt-1; ++i) {
                    msgs.back() += cur;
                }
            } else {
                if (c == '[') {
                    nums.push_back(stoi(num));
                    num.clear();
                }
                msgs.push_back(string(1, c));
            }
        }
        
        string ret;
        while (!msgs.empty()) {
            ret += msgs.front();
            msgs.pop_front();
        }
        return ret;
    }
};