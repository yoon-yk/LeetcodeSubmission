class Solution {
public:
    vector<int> lexicalOrder(int n) {
        stack<int> st;
        
        for(int i=min(9, n); i>=1; i--)
            st.push(i);

        vector<int> ans;
        
        while (!st.empty()){
            
            int tp=st.top(); st.pop();
            
            ans.push_back(tp);
            
            for(int i=9;i>=0;i--){
                int next = tp*10 + i;
                if (next<=n)
                    st.push(next);   
            }
        }
        
        return ans;
    }
};