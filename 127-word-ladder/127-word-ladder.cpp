class Solution {
public:
    int wordLen;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> Q;
        
        if (wordSet.find(endWord) == wordSet.end())
            return 0;
        
        wordLen = beginWord.length(); 
        Q.push(beginWord);
        
        string curWord, nextWord;
        int curQsize, curPath = 0, curIdx;
        while (!Q.empty()) {
            ++curPath;

            curQsize = Q.size();
            while (curQsize--) {
                curWord = Q.front(); Q.pop();
                if (curWord == endWord) 
                    return curPath;
                wordSet.erase(curWord);
                
                nextWord = curWord;
                for (int i=0; i<wordLen; i++) {
                    for (int k=0; k<26; k++) {
                        nextWord[i] = k + 'a';
                        if (wordSet.find(nextWord)!=wordSet.end())
                            Q.push(nextWord);
                        nextWord[i] = curWord[i];
                    }
                }
            }
        }
        
        return 0;
    }
};