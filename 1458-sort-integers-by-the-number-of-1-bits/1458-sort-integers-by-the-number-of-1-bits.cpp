class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            bitset<32> aa(a), bb(b);
            int cntA = aa.count(), cntB = bb.count();
            if (cntA == cntB) return a < b;
            return cntA < cntB;
        });
        return arr;
    }
};