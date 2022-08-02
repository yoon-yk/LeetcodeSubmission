class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        int curSum;
        while (left < right) {
            curSum = numbers[left] + numbers[right];
            if (curSum == target) {
                return {left+1, right+1};
            }
            
            if (curSum < target) {
                left ++;
            } else {
                right--;
            }
        }
        return {left+1, right+1};
    }
};