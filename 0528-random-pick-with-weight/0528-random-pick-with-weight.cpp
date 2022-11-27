class Solution {
    vector<int> prefixSums;
public:
    /*
    1 5 7
    1 6 13
    */
    
    Solution(vector<int> &w) {
        for (auto n : w)
            prefixSums.push_back(n + (prefixSums.empty() ? 
                0 : prefixSums.back()));
    }

    int pickIndex() {
        // generate a random number in the range of [0, 1]
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSums.back();

        // run a linear search to find the target zone
        return lower_bound(prefixSums.begin(), prefixSums.end(), target) - prefixSums.begin();
    }
};