class Solution {
public:
   string pushDominoes(string s){
        int n = s.length();
        vector<int> l(n), r(n); // each value represents the distance from the affecting root 
       
        // 1. Calculate the distance from the closest 'R' element
        int dist = INT_MAX;
        for (int i=0; i<n; i++){ // Starting from the first element
            if (s[i] == 'R') 
                dist = 0;
            else if (s[i] == 'L') dist = INT_MAX;
            else if (dist != INT_MAX && s[i] == '.') dist++;
            r[i] = dist;
        }
       
        // 2. Calculate the distance from the closest 'L' element
        dist = INT_MAX;
        for (int i=n-1; i>=0; i--){ // Starting from the last element
            if (s[i] == 'L')
                dist = 0;
            else if(s[i] == 'R') dist = INT_MAX;
            else if (dist != INT_MAX && s[i] == '.') dist++;
            l[i] = dist;
        }
       
        // Update the current string
        for (int i=0; i<n; i++){
            if (l[i] == r[i]) continue; 
            else if (l[i] > r[i]) s[i] = 'R'; 
            else s[i] = 'L';
        }
       
        return s;
    }
};