//Approach-2 : O(n^2)dp
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        vector<long long> t(n+1, 0);
        //t[j] = max distance that I can reach using j fuelStops
        
        //When I don't use any fuelStop, I can travel as much as I had startFuel in the beginning
        t[0] = startFuel;
        
        for(int i = 1; i<n+1; i++) {
            //traverse on all fuel stops
            
            //I can use all i fuelStops, or (i-1), or (i-2) ... till 0 to find which gave me best result
            //So. j goes from j = i to j = 0
            for(int j = i; j > 0; j--) {
                //But first, I need to check If I can even reach curr station or not to use it
                if(t[j-1] >= stations[i-1][0]) {
                    //So, we can use this fuelStop and now we are using (j+1) fuelStops
                    t[j] = max(t[j], t[j-1] + stations[i-1][1]);
                }
            }
        }
        
        //After you end up with all stations, check which was best for reaching target
        //Best means, minimum j used by you to reach target
        
        for(int j = 0; j<n+1; j++) {
            if(t[j] >= target)
                return j;
        }
        
        return -1;
    }
};