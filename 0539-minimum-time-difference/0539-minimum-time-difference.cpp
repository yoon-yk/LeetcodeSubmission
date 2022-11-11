class Solution {
public:
    int dayInMins = 24*60;
    /*
    00 : 00 == 24 : 00
    13 : 00
    
    13시간, 11시간 차이
    
    01:00
    15:00
    
    14시간 차이, 10시간 차이 
    */
    
    int stringToMiniutes(vector<string>& timePoints, int idx) {
        // return stoi(timePoints[idx].substr(0, 2)) * 60 + stoi(timePoints[idx].substr(3, 2));
        return timePoints[idx][0] * 600 + timePoints[idx][1] * 60 + timePoints[idx][3] * 10 + timePoints[idx][4];
    }
    
    int getTimeDifference(vector<string>& timePoints, int left, int right) {
        int leftM = stringToMiniutes(timePoints, left);
        int rightM = stringToMiniutes(timePoints, right);
        int diff = abs(leftM-rightM);
        
        return min(diff, dayInMins - diff);
    }
    
    int timeDifference(vector<string>& timePoints, int idx) {
        int left = idx, right = idx+1;
        if (right >= timePoints.size()) right %= timePoints.size();
        
        return getTimeDifference(timePoints, left, right);
    }
    
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        
        int ans = dayInMins;
        for (int i=0; i<timePoints.size(); i++) {
            ans = min(ans, timeDifference(timePoints, i));
        }
                
        return ans;
    }
};