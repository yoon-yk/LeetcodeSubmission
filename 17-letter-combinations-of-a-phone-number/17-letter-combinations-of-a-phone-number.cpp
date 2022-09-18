class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0){
            return ans;
        }  
        
        int index = 0;
        string curString = "";
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,index,curString,ans,mapping);
        return ans;
    }
    
    void solve(string& digits, int index, string& curString,vector<string>& ans, vector<string>& mapping){
        
        if (index >= digits.length()){
            ans.push_back(curString);
            return;
        }
        
        int number = digits[index] - '0';
        string value = mapping[number];
        for (int i=0;i<value.length();i++){
            curString.push_back(value[i]);
            solve(digits,index+1,curString,ans,mapping);
            curString.pop_back();
        }
    }
};