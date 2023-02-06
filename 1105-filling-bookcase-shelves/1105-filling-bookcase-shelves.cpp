class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        int n = books.size();
        vector<int> minH(n+1);
        minH[0] = 0, minH[1] = books[0][1];
        
        for (int i=2; i<=books.size(); ++i) {
            
            minH[i] = minH[i-1] + books[i-1][1]; // 새로운 층
            
            int j=i, curWidth = shelfWidth, curMaxH = books[i-1][1];
            for (; j>0 && curWidth >= books[j-1][0]; --j) {
                curWidth -= books[j-1][0];
                curMaxH = max(books[j-1][1], curMaxH);
                minH[i] = min(minH[j-1] + curMaxH, minH[i]); // 끼워넣기 
            }       
        }
        
        return minH.back();
    }
    
};