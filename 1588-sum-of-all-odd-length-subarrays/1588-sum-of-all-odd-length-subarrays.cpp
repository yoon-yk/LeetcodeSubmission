class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        // prefix + sliding window
        
        arr.push_back(0);
        for (int i=arr.size()-1; i > 0; i--)
            arr[i] = arr[i-1]; 
        arr[0] = 0;        
        for (int i=1; i<arr.size(); i++)
            arr[i] += arr[i-1]; // don't need extra space 
        
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