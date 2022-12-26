class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, h = people.size()-1, boats = 0;
        while (l <= h) {
            if (l < h && people[l] + people[h] <= limit) {
                ++boats, ++l, --h;
            } else {
                ++boats, --h;
            }
        }
        
        return boats;
    }
};