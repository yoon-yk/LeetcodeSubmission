class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highA = 0, currA = 0;
        for (const int& g : gain) {
            currA += g;
            highA = max(highA, currA);
        }
        return highA;
    }
};