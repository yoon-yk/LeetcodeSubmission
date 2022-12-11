class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        /*
        
        [0,2] [3,4] [5,7]
           [1,6]
        
        
        <----> <------> <-->
    
        */
        
        vector<vector<int>> ans;
        auto it = upper_bound(intervals.begin(), intervals.end(), toBeRemoved);


        if (it != intervals.begin()) {

            for (auto i = intervals.begin(); i!=prev(it); ++i) 
                ans.push_back(*i);
            
            auto pre = prev(it);
            if ((*pre)[1] > toBeRemoved[0]) {
                if ((*pre)[0] < toBeRemoved[0])
                    ans.push_back({(*pre)[0], toBeRemoved[0]});
                if (toBeRemoved[1] < (*pre)[1]) 
                    ans.push_back({toBeRemoved[1], (*pre)[1]});
            } else ans.push_back(*pre);            
        }

        while (it!= intervals.end() && (*it)[1] <= toBeRemoved[1]) it++;

        if (it != intervals.end() && (*it)[0] < toBeRemoved[1] && 
            toBeRemoved[0] < (*it)[1]) {
            ans.push_back({toBeRemoved[1], (*it)[1]});
            it++;
        }
        
        while (it!= intervals.end()) {
            ans.push_back(*it); it++;
        }
        
        return ans;
    }
};