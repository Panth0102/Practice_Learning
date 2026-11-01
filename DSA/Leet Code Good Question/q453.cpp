// 453. Minimum Moves to Equal Array Elements

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int minMoves(vector<int>& nums) {
            int lo = ranges::min(nums), moves = 0;
            for (int x : nums) moves += x - lo;
            return moves;  
        }
    };