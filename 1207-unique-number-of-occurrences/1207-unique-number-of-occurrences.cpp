class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_set<int> cntSet;
        int j, cnt = 0, n = arr.size();
        for (int i=0; i<n;) {
            j = i;
            while (j < n && (arr[j] == arr[i])) j++;
            cnt = j-i+1;
            if (cntSet.count(cnt)) return false;
            cntSet.insert(cnt);
            i = j;
        }
        
        return true;
    }
};