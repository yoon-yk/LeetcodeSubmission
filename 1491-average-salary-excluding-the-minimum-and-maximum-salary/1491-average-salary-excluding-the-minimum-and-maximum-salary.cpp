    using pii = pair<int, int>;

class Solution {
public:
    
    double average(vector<int>& salary) {
        size_t sz = salary.size();
        auto minmaxx = minmax_element(salary.begin(), salary.end());
        double sum = accumulate(salary.begin(), salary.end(), (double)0);
        return (sum - (*minmaxx.first + *minmaxx.second)) / (sz-2);
    }
};