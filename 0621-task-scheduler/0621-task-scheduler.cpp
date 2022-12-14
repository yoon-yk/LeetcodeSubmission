class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto & task : tasks)
            ++freq[task-'A'];

        priority_queue<int> pq; 
        for (int i=0; i<26; ++i) {
            if (freq[i]) pq.push(freq[i]);
        }
        
        int maxFreq = pq.top();
        int maxCnt = 0;
        while (!pq.empty() && pq.top() == maxFreq) {
            pq.pop();
            maxCnt ++;
        }
        
        
        /*
        a ** a ** a
        a a a 
        a * * a * * a * * a * * a * * a
        */
        
        return max(((maxFreq-1) * n) + maxFreq + (maxCnt-1), (int)tasks.size());
        
    }
};