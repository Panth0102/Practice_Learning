// Added a code for Twisted Mirror Path Count

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        const int mod = 1e9 + 7;
        int solve(int i, int j, int m, int n, int dir, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
            if (i == m - 1 && j == n - 1) return 1;
            if (i >= m || j >= n) return 0;
            if (dp[i][j][dir] != -1) return dp[i][j][dir];
            if (grid[i][j] == 1) {
                if (dir == 1)   
                    return dp[i][j][dir] = solve(i + 1, j, m, n, 0, grid, dp) % mod;
                return dp[i][j][dir] = solve(i, j + 1, m, n, 1, grid, dp) % mod;
            }
            int moveRight = solve(i, j + 1, m, n, 1, grid, dp);
            int moveDown = solve(i + 1, j, m, n, 0, grid, dp);
            return dp[i][j][dir] = (moveRight + moveDown) % mod;
        }
    
        int uniquePaths(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
            int dir = 0;
            return solve(0, 0, m, n, dir, grid, dp);
        }
    };