class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> years;
        for (auto & log : logs) {
            ++years[log[0]], --years[log[1]];
        }
        
        int prefix = 0, maxPop = 0, maxYear = -1;
        for (auto & [year, pop] : years) {
            prefix += pop;
            if (maxPop < prefix) {
                maxPop = prefix;
                maxYear = year;
            }
        }
        
        return maxYear;
    }
};