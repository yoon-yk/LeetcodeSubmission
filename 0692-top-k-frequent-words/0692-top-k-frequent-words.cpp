class Solution {
public:
    struct freqWord{
        int freq;
        string word;
        freqWord (int _freq, string _word) : freq(_freq), word(_word) {};
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        // hash map -- save freq + word
        unordered_map<string, int> mp;
        for (string & str : words)
            mp[str] ++;
        
        // min heap -- keep only k words
        auto compare = [](freqWord& w1, freqWord &w2){
            if (w1.freq == w2.freq) 
                return w1.word < w2.word;
            return w1.freq > w2.freq;
        };
        
        priority_queue<freqWord, vector<freqWord>, decltype(compare)> minHeap(compare);
        // push elem 
        string word;
        int freq; 
        for (auto & curElem : mp) {
            word = curElem.first;
            freq = curElem.second;
            minHeap.push(freqWord(freq, word));
            
            if (minHeap.size() > k)
                minHeap.pop();
        }
        
        // if the size reaches k, pop elem
        vector<string> ans(k);
        for (int i=k-1; i>=0; i--) {
            ans[i] = minHeap.top().word;
            minHeap.pop();
        }
        // declare ans;
        // from the least freq to most freq;
        // insert the array by its idx
        
        // return ans;
        return ans;
        
    }
};