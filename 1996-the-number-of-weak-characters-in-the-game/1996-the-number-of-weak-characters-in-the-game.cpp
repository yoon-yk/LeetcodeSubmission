class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        int maxAttack = -1;
        unordered_map<int, int> maxDefense;
        // Store the maximum defense for an attack value
        for (vector<int>& p : properties) {            
            maxDefense[p[0]] = (maxDefense.count(p[0]))? max(maxDefense[p[0]], p[1]) : p[1];
            maxAttack = max(maxAttack, p[0]);
        }

        // Store the maximum defense for attack greater than or equal to a value
        for (int i = maxAttack - 1; i >= 0; i--) {
            maxDefense[i] = max(maxDefense[i], maxDefense[i + 1]);
        }
        
        int weakCharacters = 0;
        for (vector<int>& property : properties) {
            int attack = property[0];
            int defense = property[1];
            
            // If their is a greater defense for properties with greater attack
            if (defense < maxDefense[attack + 1]) {
                weakCharacters++;
            }
        }
        
        return weakCharacters;
    }
};