class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string, vector<string>> contentMap;
        
        // Read and save each directory info in Trie
        for (string& curDir : paths) {
            int curIdx = 0;
            string folderName;
            
            while (curDir[curIdx]!=' ') {
                folderName+=curDir[curIdx++];
            }
            
            curIdx++;
            string content, fileName;
            while (curIdx < curDir.size() && curDir[curIdx]!=' ') {
                
                while (curDir[curIdx]!='('){
                    fileName+= curDir[curIdx];
                    curIdx++;
                }
                
                curIdx++;
                while (curDir[curIdx]!=')'){
                    content+= curDir[curIdx];
                    curIdx++;
                }
                curIdx++;
                while (curIdx < curDir.size() && curDir[curIdx] == ' ') curIdx++;
       
                // contentMap[content] = insertTrie(root);
                contentMap[content].push_back(folderName+"/"+fileName);
                
                content = "";
                fileName = "";
            }
            
        }
        
        vector<vector<string>> ans;
        for (auto & content : contentMap) {
            vector<string> tmp;
            if (content.second.size() < 2) continue; 
            for (auto & path : content.second) 
                tmp.push_back(path);
            ans.push_back(tmp);
        }
 
        return ans;
    }
};