class Solution {
public:   
    unordered_map<int, int> steps;
    
    int partition(vector<int>&v, int start, int end) {
        int rdIdx = start + rand() % (end-start+1);
        swap(v[rdIdx], v[end]);
        
        int lo = start;
        for (int i=start; i<end; ++i) {
            if (steps[v[i]] < steps[v[end]] ||
                (steps[v[i]] == steps[v[end]] && v[i] < v[end])) {
                swap(v[lo], v[i]);
                lo++;
            }
        }
        swap(v[lo], v[end]);
        return lo;
    }
    
    void quicksort(vector<int>&v, int start, int end, int k) {
        if (start >= end) return;
        int idx = partition(v, start, end);
        if (idx == k) return;
        if (idx < k) quicksort(v, idx+1, end, k);
        quicksort(v, start, idx-1, k);
    }
    
    int getKth(int lo, int hi, int k) {
        /*
        1 = 1 (0)
        2 = 1 (1)
        3 = 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1 (7)
        4 = 12 -> 6 -> 3 -> 10 -> ... 
        5 = 16 -> 8 -> ... 
        */
        
        steps[1] = 0;
        vector<int> v;
        for (int i=lo; i<=hi; ++i) {v.push_back(i); getSteps(i);}
        quicksort(v, 0, v.size()-1, k-1);
        
        return v[k-1];
    }
    
    int getSteps(int n) {
        if (steps.count(n)) return steps[n];

        if (n & 1) return steps[n] = getSteps(n*3+1) + 1; // odd 
        return steps[n] = getSteps(n >> 1) + 1;
    };
    
};