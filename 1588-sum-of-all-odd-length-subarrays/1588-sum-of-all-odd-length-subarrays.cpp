class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        // prefix + sliding window
        
        arr.push_back(0);
        
        int prev = arr[0];
        int curr;
        arr[0] = 0;        
        for (int i=1; i<arr.size(); i++) {
            curr = arr[i];
            arr[i] = prev + arr[i-1]; // don't need extra space
            prev = curr;
        }

        
        // 1, 5, 7, 12, 15 
        int sum = 0; 
        for (int wSize = 1; wSize < arr.size(); wSize += 2 ) {
            for (int left = 0, right = left + wSize; right < arr.size(); left++, right++ ) {
                sum += arr[right] - arr[left];
            }
        }
        
        return sum;
    }
};