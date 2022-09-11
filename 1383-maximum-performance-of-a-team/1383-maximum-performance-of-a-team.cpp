class Solution {
public:
    
    struct Node {
        long long speed;
        long long efficiency;
        Node(long long _speed, long long _efficiency) :
            speed(_speed), efficiency(_efficiency) {};
    };
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
    int MOD = 1e9 + 7;
    
    auto compareSpeed = [] (Node*& a, Node*& b) {
      if (a->speed == b->speed) 
          return a->efficiency < b->efficiency;
        return a->speed < b->speed;
    };
        
    auto minEfficiency = [] (Node*& a, Node*& b) {
      if (a->efficiency == b->efficiency) 
          return a->speed > b->speed;
        return a->efficiency > b->efficiency;
    };
        
        priority_queue<Node*, vector<Node*>, decltype(compareSpeed)> speedMaxQ(compareSpeed);
        priority_queue<Node*, vector<Node*>, decltype(minEfficiency)> effMinQ(minEfficiency);
        
        for (int i=0; i<n; i++) {
            speedMaxQ.push(new Node(speed[i], efficiency[i]));
        }
        
        long long minEff;
        long long maxPerformance = 0;
        long long curSpeedSum = 0;
        
        for (int i=0; i<k; i++) {
            auto cur = speedMaxQ.top(); speedMaxQ.pop();
            cout << cur->speed << "||" << cur->efficiency << endl;
            effMinQ.push(cur);
            minEff = effMinQ.top()->efficiency;
            curSpeedSum += cur->speed;
            maxPerformance = max(maxPerformance, (curSpeedSum * minEff));
            // cout << "(curSpeedSum) : " << curSpeedSum << " | (minEff) : " << minEff << " | (currPf) : " << (curSpeedSum * minEff) % MOD <<" | (maxPf) : " << maxPerformance << endl;

        }
        
        while (!speedMaxQ.empty()) {
            curSpeedSum -= effMinQ.top()->speed;
            // cout << "(pop)" << effMinQ.top()->speed << "||" << effMinQ.top()->efficiency << endl;
            effMinQ.pop();

            auto newMember = speedMaxQ.top(); speedMaxQ.pop();
            // cout << "(replace)" << newMember->speed << "||" << newMember->efficiency << endl;

            curSpeedSum += newMember->speed;
            effMinQ.push(newMember); 
            
            minEff = effMinQ.top()->efficiency;
            maxPerformance = max(maxPerformance, (curSpeedSum * minEff));
            
            // cout << "(curSpeedSum) : " << curSpeedSum << " | (minEff) : " << minEff << " | (currPf) : " << (curSpeedSum * minEff) <<" | (maxPf) : " << maxPerformance << endl;
        }
        
        while (!effMinQ.empty()) {
            curSpeedSum -= effMinQ.top()->speed;
            effMinQ.pop();
            cout << "(pop)" << effMinQ.top()->speed << "||" << effMinQ.top()->efficiency << endl;

            minEff = effMinQ.top()->efficiency;
            maxPerformance = max(maxPerformance, (curSpeedSum * minEff));
            // cout << "(curSpeedSum) : " << curSpeedSum << " | (minEff) : " << minEff << " | (currPf) : " << (curSpeedSum * minEff) % MOD <<" | (maxPf) : " << maxPerformance << endl;
        }
        
        return maxPerformance % MOD;
        
        
    }
};