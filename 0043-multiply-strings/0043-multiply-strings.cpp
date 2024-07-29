class Solution {
public:
    string multiply(string num1, string num2) {
        // Edge case: if either number is "0", return "0"
        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size(), n2 = num2.size();
        vector<int> result(n1 + n2, 0);

        // Perform multiplication digit by digit
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10; // Store the single digit
                result[i + j] += sum / 10;    // Carry over
            }
        }

        // Convert the result vector to a string
        string ans;
        for (int num : result) {
            if (!(ans.empty() && num == 0)) { // Skip leading zeros
                ans += to_string(num);
            }
        }

        return ans.empty() ? "0" : ans;
    }
};
