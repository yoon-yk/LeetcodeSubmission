class Solution {
public:
    string multiply(string num1, string num2) {
        
        if (num1 == "0" || num2 == "0") return "0";
        int size = num1.size() + num2.size();
        vector<int> res(size, 0);
        
        int idx;
        for (int i=num1.size()-1; i>=0; i--){ // first num
            idx = i + num2.size();
            for (int j=num2.size()-1; j>=0; j--){ // second num
                res[idx] += (num1[i]-'0')* (num2[j]-'0');
                res[idx-1] += res[idx]/10;
                res[idx] %= 10;
                idx--;
            }
        }
        
        int i=0;
        string ans="";
        while(res[i]==0) i++;
        while(i<res.size()) ans+=to_string(res[i++]);
        
        return ans;
        
    }
};