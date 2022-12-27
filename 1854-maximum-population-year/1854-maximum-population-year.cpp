class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int base = 1950;
        vector<int> years(105);
        for (auto & log : logs) {
            ++years[log[0]-base], --years[log[1]-base];
        }
        
        int pop, prefix = 0, maxPop = 0, maxYear = -1;
        for (int i=0; i<=101; ++i) {
            pop = years[i]; 
            prefix += pop;
            if (maxPop < prefix) {
                maxPop = prefix;
                maxYear = i + base;
            }
        }
        
        return maxYear;
    }
};