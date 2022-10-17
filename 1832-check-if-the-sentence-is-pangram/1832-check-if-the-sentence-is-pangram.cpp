class Solution {
public:
    bool checkIfPangram(string sentence) {
        long long check = 0;
        for (auto &ch : sentence) {
            check |= (1 << (ch-'a'));
        }
        // cout << check << endl;
        // cout << ((1<<26)-1) << endl;
        // cout << (check == ((1<<26)-1)) << endl;
        return (check == ((1<<26)-1));
    }
};