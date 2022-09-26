class Solution {
public:
    /*
    a==b / b!=a 
    
    if '==', check if it is not confirmed to be different
    if '!=', check if it is not confirmed to be the same
    
    matrix 
        a  b  c  d 
     a -1 -1 -1 -1
     b 
     c
     d
    
    -1 => no link 
     0 => can't be the same
     1 => should be the same
    
    */
    
    vector<int> parent;
    
    int findd (int x) {
        if (x == parent[x]) return x;
        return findd(parent[x]);
    }
    
    void unionn (int x, int y) {
        int xP = findd(x);
        int yP = findd(y);
        parent[xP] = yP;
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        
        for (int i=0; i<26; i++) 
            parent[i] = i;
            
        char x, y, e;
        int xP, yP;
        for (auto & eq : equations) {
            if (eq[1] == '=') {
                x = eq[0] - 'a', y = eq[3] - 'a';
                unionn(findd(x), findd(y));
            } 
            
        }
        
        for (auto & eq : equations) {
            if (eq[1] == '!') {
                x = eq[0] - 'a', y = eq[3] - 'a';
                if (findd(x) == findd(y))  return false;
            } 
        }
        
        return true;
    }
};