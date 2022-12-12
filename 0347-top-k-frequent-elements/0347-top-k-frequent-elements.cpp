class Solution {
public:
    unordered_map<int, int> hashM;
    
    int partition(int start, int end, vector<int>& vals) {   

        int lo = start;
        for (int i=start; i<end; i++) {
            if (hashM[vals[i]] < hashM[vals[end]]) {
                swap(vals[i], vals[lo]);
                lo++;
            } 
        }
        
        swap(vals[lo], vals[end]);
        
        return lo;
    }
    
    void quicksort(int start, int end, vector<int>& vals, int k) {
        
        if (start == end) return;
        int randIdx = start + (rand() % (end-start+1));
        swap(vals[randIdx], vals[end]);
        
        int partitionIdx = partition(start, end, vals);
        if (partitionIdx == k) return;
        else if (partitionIdx < k) {
            quicksort(partitionIdx+1, end, vals, k);
        } else {
            quicksort(start, partitionIdx-1, vals, k);
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        for (auto & n : nums) hashM[n]++;
        
        vector<int> values;
        for (auto & [val, freq] : hashM)
            values.push_back(val);
        
        int n = values.size();
        // 0 1 2 3 4 5 6 7
        quicksort(0, n-1, values, n-k);
        
        vector<int> ans(values.begin()+n-k, values.end());
        return ans;
        
    }
};