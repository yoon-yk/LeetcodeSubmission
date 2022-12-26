class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        vector<const char*> pool, nextPool;
        for (auto & word : words) {
            pool.push_back(word.c_str());
        }
        for (auto & c : pref) {
            for (auto & cand : pool) 
                if (c == *cand) nextPool.push_back(++cand);
            pool.clear();
            pool.swap(nextPool);
        }
        return pool.size();
    }
};