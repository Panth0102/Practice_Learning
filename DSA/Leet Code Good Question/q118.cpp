//  Q118 and 119 Pascal Traingles

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            vector<int> add(i+1, 1);
            for(int j =1; j <i; j++){
                add[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(add);
        }
        return ans;
    }
};



// For finding a particular row

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0; i <= rowIndex; i++){
            vector<int> add(i+1,1);
            for(int j = 1; j <i; j++){
                add[j] = ans[j] + ans[j-1];
            }
            ans = add;
        }
        return ans;
    }
};