// Q51 N-Queens
// Not Optimal

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
    public:
    
        int N;
        vector<vector<string>> v;
    
        bool issafe(vector<vector<int>> mat,int row,int col){
            int i,j;
            for(i=0;i<col;i++)
                if(mat[row][i]) return false;
    
            for(i=row,j=col;   i>=0 && j>=0;   i--,j--){
                if(mat[i][j]) return false;
            }
            for(i=row,j=col;   i<N && j>=0;   i++,j--){
                if(mat[i][j]) return false;
            }
            return true;
            
        }
        void nqueen(vector<vector<int>> mat, int col){
            if(col>=N){     
                vector<string> v1;
                for(auto i:mat){
                    string s;
                    for(auto j:i){
                        if(j==1)  s+='Q';
                        else        s+='.';
                    }
                    v1.push_back(s);
                }
                v.push_back(v1);
            }
    
            for(int i=0;i<N;i++){
                if(issafe(mat,i,col)){
                    mat[i][col]=1;
                    nqueen(mat,col+1);
                    mat[i][col]=0;
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int n) {
            N=n;
            vector<vector<int>> mat;
            for(int i=0;i<n;i++){
                vector<int> v11;
                for(int j=0;j<n;j++){
                    v11.push_back(0);
                }      
                mat.push_back(v11);  
            }
            nqueen(mat,0);
            return v;
        }
    };