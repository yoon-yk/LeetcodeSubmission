class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
    
        vector<string> chars = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        
        unordered_map<string, int> m;
        
        for (string & word : words) {
            string w = "";
            for (char & ch : word) {
                w += chars[ch-'a'];
            }
            m[w]++;
        }
        
        return m.size();
    }
};