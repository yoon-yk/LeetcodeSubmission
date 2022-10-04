class Solution {
public:
    bool divisorGame(int n) {
        
        // Alice wins when n is 1 in Bob's turn
        
        // n = 2
        // alice choses 1
        
        // n = 3
        // alice chooses 1
            // n = 2, bob c 1
            // n = 1, alice loses
        
        // alice chooses 2
            // n = 1 in bob's turn
        
        // alice needs to choose the biggest number 
        // 13 
        // 13 % x == 0, x == 1 / 12 
        // 12 % x == 0, x == 0 / 11
        
        return n%2 == 0;
        
    }
};