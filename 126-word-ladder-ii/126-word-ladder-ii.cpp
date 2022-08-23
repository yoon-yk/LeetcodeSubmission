class Solution 
{
    vector<vector<string>> result;
    
    void printPath(const vector<vector<int>> &parents, const vector<string>& wordList, int currNode, vector<string> &path, int pathIndex)
    {
        if (parents[currNode].empty())
        {
            result.push_back(path);
            return;
        }
        
        for(auto &e: parents[currNode])
        {
            path[pathIndex] = wordList[e];
            printPath(parents, wordList, e, path, pathIndex - 1);
        }
    }
     
public:
    inline vector<vector<string>> findLadders(const string &beginWord, const string &endWord, const vector<string>& wordList) 
    {
        srand(time(NULL) ^ rand());
        unordered_map<string, vector<int>> mp;
        
        string prefix = "";
        bool endWordExists = false;
        for(int i = 0; i < wordList.size(); ++i)
        {
            if(wordList[i] == endWord) endWordExists = true;
            
            prefix = "";
            for(int j = 0; j < wordList[i].size(); ++j)
            {
                mp[prefix + "*" + wordList[i].substr(j+1)].push_back(i);
                prefix += wordList[i][j];
            }
        }
        
        if(!endWordExists) return vector<vector<string>>();
        
        queue<int> Q;
        prefix = "";
        vector<int> distance(wordList.size(), -1);
        for(int i = 0; i < beginWord.size(); ++i)
        {
            if(mp.count(prefix + "*" + beginWord.substr(i+1)))
            {
                for(const auto &j: mp[prefix + "*" + beginWord.substr(i+1)])
                {
                    Q.push(j);
                    distance[j] = 1;
                }
            }
            prefix += beginWord[i];
        }
        
        if (Q.empty()) return vector<vector<string>>();
        
        vector<int> endNodes;
        vector<vector<int>> parents(wordList.size());
        while(Q.size() && endNodes.empty())
        {
            int sz = Q.size() + 1;
            while(--sz)
            {
                auto i = Q.front();
                Q.pop();

                if(wordList[i] == endWord)
                {
                    endNodes.push_back(i);
                    continue;
                }

                prefix = "";
                for(int j = 0; j < wordList[i].size(); ++j)
                {
                    if(mp.count(prefix + "*" + wordList[i].substr(j+1)))
                    {
                        for(const auto &k: mp[prefix + "*" + wordList[i].substr(j+1)])
                        {
                            if(distance[k] == -1)
                            {
                                Q.push(k);
                                parents[k].push_back(i);
                                distance[k] = distance[i] + 1;
                            }
                            else if (distance[k] == distance[i] + 1)
                            {
                                parents[k].push_back(i);
                            }
                        }
                    }
                    prefix += wordList[i][j];
                }
            }
        }
        
        if (endNodes.empty()) return vector<vector<string>>();
        
        vector<string> path(distance[endNodes.front()] + 1);
        path[0] = beginWord;
        for(auto &e: endNodes)
        {
            path[distance[endNodes.front()]] = wordList[e];
            printPath(parents, wordList, e, path, distance[endNodes.front()] - 1);
        }
        
        return result;
    }
};