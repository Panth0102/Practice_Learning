// Q1254 Number of close islands

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
        int closedIsland(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            int count = 0;
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};
    
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (grid[r][c] != 0) continue;
    
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    grid[r][c] = 1;
                    bool closed = true;
    
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
    
                        if (x == 0 || x == m - 1 ||
                            y == 0 || y == n - 1)
                            closed = false;
    
                        for (int i = 0; i < 4; i++) {
                            int nx = x + dr[i];
                            int ny = y + dc[i];
    
                            if (nx >= 0 && nx < m &&
                                ny >= 0 && ny < n &&
                                grid[nx][ny] == 0) {
                                grid[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
    
                    if (closed) count++;
                }
            }
    
            return count;
        }
    };