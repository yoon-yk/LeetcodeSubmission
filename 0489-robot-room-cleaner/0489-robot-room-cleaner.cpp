/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

/*
--------------
-     *    ---
---   ---   --
--------------

*/

class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1}; // up, left, down, right

    void cleanRoom(Robot& robot) {
        int curR = 0, curC = 0, curD = 0;
        unordered_map<int, unordered_set<int>> visited;
        dfs(robot, curR, curC, curD, visited);
    }


    void backToOriginalState(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    
    void dfs(Robot& robot, int r, int c, int d, unordered_map<int, unordered_set<int>>& visited) {
        
        robot.clean();
        visited[r].insert(c);
        
        int newR, newC, newD;
        bool canMove;
        
        for (int i=0; i<4; i++) {
            newD = (d+i)%4;
            newR = r + dir[newD], newC = c + dir[newD+1];
            if (!visited[newR].count(newC) && robot.move()) {
                dfs(robot, newR, newC, newD, visited);
                backToOriginalState(robot);
            }
            robot.turnRight();
        }
        
        
        // curDir 
        // curDir+1 // turn right
        // curDir+2 // turn right*2
        // curDir+3 // turn right*3
    }
};