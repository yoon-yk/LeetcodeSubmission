class Solution {
public:
    
    /*
    
    BFS? DP?
    - Pacific Ocean : (0 <= i < height.size() && j == 0 ) || (i==0)
    - Atlantic Ocean : (i > 0 && j == height[i].size() ) || (i==height.size())
    
    ********
    * 2, 1 #
    * 1, 2 #
    ########
    
    ***********
    * 3, 1, 3 #
    * 2, 1, 5 #
    * 5, 6, 7 #
    ###########
    
    - edge에 있는 애들은 모두 흘러갈 수 있음. (xxxxx)
    - DFS로 하나씩 타고 가기 -> {
        - Pacific Ocean으로 가려면 left, top으로만 가야함.
        - Atlantic Ocean으로 가려면 right, bottom으로만 가야함.
        - reachedPacific && reachedAtlantic 인 경우에 true 반환하기
    }
    
    */
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> res;
        int rowSize = heights.size(), colSize = heights[0].size();
        vector<vector<int>> toPacific (rowSize, vector<int> (colSize, 0));
        vector<vector<int>> toAtlantic (rowSize, vector<int> (colSize, 0));
        
        // left, right
        for (int i=0; i<heights.size(); i++) {
            isReacheable(heights, i, 0, INT_MIN, toPacific); // left (pacific)
            isReacheable(heights, i, heights[0].size()-1, INT_MIN, toAtlantic); // right (atlantic)
        }
        
        // top, bottom
        for (int j=0; j<heights[0].size(); j++) {
            isReacheable(heights, 0, j, INT_MIN, toPacific); // top (pacific)
            isReacheable(heights, heights.size()-1, j, INT_MIN, toAtlantic); // bottom (atlantic)
        }
        
        for (int i=0; i<heights.size(); i++) {
            for (int j=0; j<heights[i].size(); j++) {
                if ((toPacific[i][j] == 1) && (toAtlantic[i][j] == 1))
                    res.push_back({i, j});
            }
        }
        
        return res;
    }
    
    void isReacheable (vector<vector<int>>& heights, int i, int j, int preVal, vector<vector<int>>& ocean) {
        
        // 1. Exit Condition
        if (i<0 || i>heights.size() -1 || j <0 || j>heights[0].size()-1)
            return;
        if (ocean[i][j] == 1) 
            return;
        if (preVal > heights[i][j])
            return;
        
        // 2. Process DFS
        ocean[i][j] = 1;
        
        // 3. Call DFS 
        isReacheable (heights, i+1, j, heights[i][j], ocean); // down
        isReacheable (heights, i, j-1, heights[i][j], ocean); // left

        isReacheable (heights, i-1, j, heights[i][j], ocean); // top
        isReacheable (heights, i, j+1, heights[i][j], ocean); // right     

    }

    
};