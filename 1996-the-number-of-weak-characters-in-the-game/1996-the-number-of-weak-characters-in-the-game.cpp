class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        int maxAttack = -1, minAttack = INT_MAX;
        vector<int> maxDefense (100002,0);
        // Store the maximum defense for an attack value
        
        for (auto & p : properties) {            
            maxDefense[p[0]] = max(maxDefense[p[0]], p[1]);
            maxAttack = max(maxAttack, p[0]);
            minAttack = min(minAttack, p[0]);
        }

        // Store the maximum defense for attack greater than or equal to a value
        for (int i = maxAttack - 1; i >= minAttack; i--) {
            maxDefense[i] = max(maxDefense[i], maxDefense[i + 1]);
        }
        
        int weakCharacters = 0;
        for (auto & p : properties) {
            // If their is a greater defense for properties with greater attack
            if (p[1] < maxDefense[p[0] + 1])
                weakCharacters++;
        }
        
        return weakCharacters;
    }
};