class Solution {
public:
    bool checkIfPangram(string sentence) {
        long long check = 0;
        for (auto &ch : sentence) 
            check |= (1 << (ch-'a'));
        return (check == ((1<<26)-1));
    }
};