class Solution {
public:
    vector<int> unique;
    unordered_map<int, int> count_map;

    int partition(int left, int right, int pivot_index) {
        int pivot_frequency = count_map[unique[pivot_index]];
        
        // 1. Move pivot to the end
        swap(unique[pivot_index], unique[right]);
        
        // 2. Move all less frequent elements to the left
        int store_index = left;
        for (int i=left; i<=right; i++) {
            if (count_map[unique[i]] < pivot_frequency) {
                swap(unique[store_index], unique[i]);
                store_index++;
            }
        }
        
        // 3. move pivot to its final place
        swap(unique[right], unique[store_index]);
        
        return store_index;
    }
        
    void quickselect(int left, int right, int k_smallest) {
        
        // base case : the list contains only one element
        if (left == right) return;
        int pivot_index = left + rand() % (right-left+1);
        
        // find the pivot position in a sorted list
        pivot_index = partition(left, right, pivot_index);
        
        // if the pivot is in its final sorted position
        if (k_smallest == pivot_index) {
            return;
        } else if(k_smallest < pivot_index) {
            // go left
            quickselect(left, pivot_index-1, k_smallest);
        } else {
            // go right
            quickselect(pivot_index+1, right, k_smallest);
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int & n : nums) count_map[n] ++;
        
        int n = count_map.size();
        for (auto & [val, preq] : count_map)
            unique.push_back(val);
        
        quickselect(0, n-1, n-k);
        vector<int> top_k_frequent(k);
        copy(unique.begin() + n-k, unique.end(), top_k_frequent.begin());
        return top_k_frequent;
    }
};