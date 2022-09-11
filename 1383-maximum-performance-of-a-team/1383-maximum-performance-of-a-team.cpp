class Solution {
public:
    
    struct Node {
        int speed;
        int efficiency;
        Node(int _speed, int _efficiency) :
            speed(_speed), efficiency(_efficiency) {};
    };
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
    int MOD = 1e9 + 7;
    
    auto compareSpeed = [] (Node*& a, Node*& b) {
        return a->speed < b->speed;
    };
        
    auto minEfficiency = [] (Node*& a, Node*& b) {
        return a->efficiency > b->efficiency;
    };
        
        priority_queue<Node*, vector<Node*>, decltype(compareSpeed)> speedMaxQ(compareSpeed);
        priority_queue<Node*, vector<Node*>, decltype(minEfficiency)> effMinQ(minEfficiency);
        
        for (int i=0; i<n; i++) 
            speedMaxQ.push(new Node(speed[i], efficiency[i]));
        
        int minEff;
        long long maxPerformance = 0;
        long long curSpeedSum = 0;
        
        for (int i=0; i<k; i++) {
            auto cur = speedMaxQ.top(); speedMaxQ.pop();
            effMinQ.push(cur);
            curSpeedSum += cur->speed;
            minEff = effMinQ.top()->efficiency;
            maxPerformance = max(maxPerformance, (curSpeedSum * minEff));
        }
        
        while (!speedMaxQ.empty()) {
            curSpeedSum -= effMinQ.top()->speed;
            effMinQ.pop();

            auto newMember = speedMaxQ.top(); speedMaxQ.pop();
            curSpeedSum += newMember->speed;
            effMinQ.push(newMember); 
            
            minEff = effMinQ.top()->efficiency;
            maxPerformance = max(maxPerformance, (curSpeedSum * minEff));

        }
        
        while (!effMinQ.empty()) {
            curSpeedSum -= effMinQ.top()->speed;
            effMinQ.pop();

            minEff = effMinQ.top()->efficiency;
            maxPerformance = max(maxPerformance, (curSpeedSum * minEff));
        }
        
        return maxPerformance % MOD;
        
        
    }
};