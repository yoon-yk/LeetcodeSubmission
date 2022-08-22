class Solution {
public:
    int wordLen;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> hashM;
        queue<string> Q;
        
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        wordLen = beginWord.length();
        for (int i=0; i<wordList.size(); i++) {
            hashM[wordList[i]]++; 
        }
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
                hashM.erase(curWord);
                
                nextWord = curWord;
                for (int i=0; i<wordLen; i++) {
                    for (int k=0; k<26; k++) {
                        nextWord[i] = k + 'a';
                        if (hashM.count(nextWord))
                            Q.push(nextWord);
                        nextWord[i] = curWord[i];
                    }
                }
            }
        }
        
        return 0;
    }
};