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

class Solution {
public:
    
    vector<int> direc = {-1, 0, 1, 0, -1};
    
    void cleanRoom(Robot& robot) {
        unordered_map<int, int> m;
            
        int curR = 0, curC = 0;
        robot.clean();
        m[0]++;
        dfs(robot, curR, curC, 0, m);
    }
    
    void goBack(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void dfs(Robot& robot, int curR, int curC, int dir, unordered_map<int, int>& m) {
        
        int newDir, newR, newC;
        int newLoc;
        
        for (int i=0; i<4; i++) {
            newDir = (dir+i) % 4;
            newR = curR+direc[newDir];
            newC = curC+direc[newDir+1];
            newLoc = newR*10000 + newC;
            
            if (!m.count(newLoc) && robot.move()) {
                robot.clean();
                m[newLoc]++;
                dfs(robot, newR, newC, newDir, m);
                goBack(robot);
            }
            
            robot.turnRight();
        }
    }
};