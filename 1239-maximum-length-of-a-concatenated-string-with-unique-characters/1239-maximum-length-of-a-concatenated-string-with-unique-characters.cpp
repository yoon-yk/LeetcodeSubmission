class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Results initialized as a Set to prevent duplicates
        unordered_set<int> results({0});
        int best = 0;
        
        // Check each string in arr and find the best length
        for (string& word : arr) 
            best = max(best, addWord(word, results));
        return best;
    }

    // Helper to check if string has no duplicate characters
    int addWord(string& word, unordered_set<int>& results) {
        // Initialize an int to use as a character set
        int charBitSet = 0;
        int best = 0;
        for (char& c : word) {
            // Define character mask for currrent char
            int mask = 1 << (c - 'a');

            // Bitwise AND check using character mask
            // to see if char already found and if so, exit
            if ((charBitSet & mask) > 0)
                return 0;

            // Mark char as seen in charBitSet
            charBitSet += mask;
        }

        // If the initial bitset is already a known result,
        // then any possible new results will have already been found
        if (results.find(charBitSet) != results.end())
            return 0;

        // Iterate through previous results only
        // and store new results in newResults
        unordered_set<int> newResults;
        for (int res : results) {
            // If the two bitsets overlap, skip to the next result
            if (res & charBitSet)
                continue;

            // Build the new entry with bit manipulation
            int newResLen = (res >> 26) + word.size();
            int newCharBitSet = (charBitSet + res) & ((1 << 26) - 1);

            // Merge the two into one, add it to results,
            // and keep track of the longest so far
            newResults.insert((newResLen << 26) + newCharBitSet);
            best = max(best, newResLen);
        }
        
        // Merge newResults into results
        results.insert(newResults.begin(), newResults.end());
        return best;
    }
};