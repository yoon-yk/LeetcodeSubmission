class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 가장 큰 두개를 꺼내서 부순다. 
        // 케이스 1) 같은 애들은 둘다 없앤다.
        // 케이스 2) 큰 애는 작은 애를 뺀만큼만 남는다.
        // 돌이 하나만 남을 때까지 반복한다.
        
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int fStone = pq.top(); pq.pop();
            int sStone = pq.top(); pq.pop();
            
            if (fStone > sStone) {
                pq.push(fStone - sStone);
            }
        }
        return pq.empty() ? 0 : pq.top();
        
    }
};