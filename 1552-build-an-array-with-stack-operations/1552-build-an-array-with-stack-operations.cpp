class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 0;
        int sz = target.size();
        vector<string> ret;
        for (int i=0; i<sz; ++i) {
            while (cur < target[i]) {
                ret.push_back("Push");
                ++cur;
                if (cur != target[i]) {
                    ret.push_back("Pop");
                }
            }
        }

        return ret;
    }
};