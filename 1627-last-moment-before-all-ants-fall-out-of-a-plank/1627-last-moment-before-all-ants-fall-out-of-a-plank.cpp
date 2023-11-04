class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if (left.empty() && right.empty()) return 0;

        if (right.empty()) {
            return *max_element(left.begin(), left.end());

        }
        if (left.empty()) {
            return n-*min_element(right.begin(), right.end());
        }

        /*
        
        _ _ _ _ > < _ _ _ _
        0 1 2 3 4 5 6 7 8 9
        
        */

        return max(*max_element(left.begin(), left.end()), 
                    n-*min_element(right.begin(), right.end()));
    }
};