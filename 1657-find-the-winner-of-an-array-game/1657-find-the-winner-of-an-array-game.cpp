class Solution {
public:
    int getWinner(vector<int>& arr, int k) {

        if (k >= arr.size())
            return *max_element(arr.begin(), arr.end());

        deque<int> dq(arr.begin(), arr.end());

        int curWinner = -1, cnt = 0;
        while (k > 0) {
            auto& f = dq[0], &s = dq[1];
            if (f > s) swap(f, s); // keep f < s
            if (curWinner == s) ++cnt;
            else curWinner = s, cnt = 1;
            if (cnt == k) {
                return curWinner;
            }
            dq.push_back(dq.front());
            dq.pop_front();
        }

        return -1;
    }
};